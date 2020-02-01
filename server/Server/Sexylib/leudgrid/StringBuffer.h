#pragma once

namespace LEUD {

const size_t MAX_BUFFER_SIZE = 512;

class CStringImp
{
public:
	CStringImp()
	{
		m_nLength = 0;
		m_pBuffer = NULL;
	}

	explicit CStringImp(const char* pBuf, size_t nLength)
	{
		m_nLength = nLength;
		m_pBuffer = (char * )pBuf;
	}

	explicit CStringImp(const char * pszBuf)
	{
		m_nLength=::strlen(pszBuf);
		m_pBuffer=(char *)pszBuf;
	}

	const CStringImp & operator = (const CStringImp & stringSrc)
	{
		m_nLength = stringSrc.GetLength();
		m_pBuffer = (char *)stringSrc.GetBuffer();
		return (* this);
	}

	virtual ~CStringImp() {};

	const char* GetBuffer() const
	{
		return m_pBuffer;
	}

	size_t GetLength()const
	{
		return m_nLength;
	}

	operator LPCSTR() const
	{
		return m_pBuffer;
	};

	///Ϊ�����Ч�ʣ������ڴ濽�����ú�����Ѷ����cDiv�ַ��޸�Ϊ0

	//////////////////////////////////////////////////////////////////////////
	//
	//    ::OnRead(const char * pbuf,buflen)  ��һ��OnRead������
	//    pBuf ="(109/sunway/09/123/1)";
	//    CStringImp strImp(pbuf,buflen);
	//    CStringImp strBody;
	//
	//    strImp.ExtractString(strBody,'(',')');  //��鷵��ֵ
	//
	//    CStringImp strCmd,strLoginId,strFeedType,strFeedSecs,strNum;
	//
	//    strBody.FetchString('/',strCmd);    
	//    strBody.FetchString('/',strLoginId);
	//    strBody.FetchString('/',strFeedType);
	//    strBody.FetchString('/',strFeedSecs);
	//
	//    strNum = strBody;
	//    
	//
	//////////////////////////////////////////////////////////////////////////

	bool FetchString(const char cDiv, CStringImp& strPosImp)
	{
		char* psOldBuf = m_pBuffer;

		for (size_t i=0;i<m_nLength;++i)
		{
			if (psOldBuf[i] == cDiv)
			{
				psOldBuf[i] = 0;
				strPosImp.m_pBuffer = m_pBuffer;
				strPosImp.m_nLength = i;

				this->m_pBuffer += (i+1);
				this->m_nLength -= (i+1);

				return true;
			}
		}

		return false;
	}

	///Ϊ�����Ч�ʣ������ڴ濽�����ú�����Ѷ����cEnd�ַ��޸�Ϊ0

	bool ExtractString(CStringImp & strImp,const char cBegin,const char cEnd)
	{
		bool bFindHead = false;
		char * psOldBuf = m_pBuffer;
		size_t nBeginPos = 0;

		for (size_t i=0; i<m_nLength; ++i )
		{
			if (!bFindHead)
			{
				if (psOldBuf[i] == cBegin)
				{
					bFindHead =true;
					nBeginPos = i+1;
				}
			}
			else
			{
				if (psOldBuf[i] == cEnd)
				{
					psOldBuf[i] = 0;

					strImp.m_pBuffer = &psOldBuf[nBeginPos];

					strImp.m_nLength = i-nBeginPos;

					this->m_pBuffer += (i+1);
					this->m_nLength -= (i+1);

					return true;
				}
			}
		}

		return false;
	}

	int Pos(const char PosChar)
	{
		for(size_t i=0; i<m_nLength; ++i)
		{
			if(m_pBuffer[i]==PosChar)
			{
				return (int)i;
			}
		}

		return -1;
	}

	size_t size() const
	{
		return m_nLength;
	}

protected:
	char * m_pBuffer;
	size_t m_nLength;
};

template <size_t max_buffer_size=MAX_BUFFER_SIZE>
class CStringBuffer : public CStringImp
{
public:
	CStringBuffer(void)
	{
		m_pBuffer = m_Buffer;
	};

	/// ��������� strImp����
	explicit CStringBuffer(const CStringImp& strImp)
	{
		m_pBuffer = m_Buffer;

		if (strImp.GetLength() <= max_buffer_size)
		{
			memcpy(m_Buffer,strImp.GetBuffer(),strImp.GetLength());
			m_nLength = strImp.GetLength();
		}
	};

	/// �������캯��
	template<size_t size>
		explicit CStringBuffer(const CStringBuffer<size>& strbuffer)
	{
		m_pBuffer = m_Buffer;

		if (strbuffer.GetLength() <= max_buffer_size)
		{
			memcpy(this->m_Buffer,strbuffer,strbuffer.GetLength());
			m_nLength = strbuffer.GetLength();
		}
	}

	/// �����������0��β���ַ���
	explicit CStringBuffer(const char* pszStr)
	{
		size_t nLength = strlen(pszStr);

		if (nLength < max_buffer_size)
		{
			memcpy(m_Buffer,pszStr,nLength);
			m_Buffer[nLength] = 0;
			m_nLength = nLength + 1;
		}

		m_pBuffer = m_Buffer;
	};

	/// ��������� pBuf��ͷ��nLength��һ���ַ���
	explicit CStringBuffer(const char* pBuf,size_t nLength)
	{
		if (nLength <= max_buffer_size)
		{
			memcpy(m_Buffer,pBuf,nLength);
			m_nLength = nLength;
		}

		m_pBuffer = m_Buffer;
	}

	virtual ~CStringBuffer(void) {};

	/// ���ػ������ܵ�����
	size_t GetCapacity() const
	{
		return max_buffer_size;
	}

	/// ��cFill��� m_Buffer�Ļ�������������ṩ�ò�������0�ַ����
	void FillChar(const char cFill=0)
	{
		memset(m_Buffer, cFill, max_buffer_size);
	}

	/// �õ���ǰ��������ʣ��ռ��ͷ��ַ
	char * GetFreeBuffer() 
	{ 
		return &m_Buffer[m_nLength];
	};

	/// �õ�ʣ��ռ�ĳ���
	int GetFreeLength() 
	{
		return (int)(max_buffer_size-m_nLength);
	};

	/// ���ӳ��ȼ�����Ϊ���ṩ��һЩ��֪�����ȵĺ���ʹ��
	bool AddBuffer(size_t nLen)
	{
		if (m_nLength+nLen <= max_buffer_size)
		{
			m_nLength += nLen;
			return true;
		}
		else
		{
			return false;
		}
	}

	/// �õ�������ͷ��ַ
	char* GetData() const
	{
		return m_Buffer;
	};

	/// �򻺳����м����µĻ��� 
	bool AddBuffer(const char* buffer,size_t len)
	{
		if (len+m_nLength>max_buffer_size)
		{
			return false;
		}

		memcpy(&m_Buffer[m_nLength],buffer,len);
		m_nLength += len;

		return true;
	}

	/// ��stringImp�����ݼ��뵽��������
	bool AddBuffer(const CStringImp & stringImp)
	{
		if (stringImp.GetLength()+m_nLength>max_buffer_size)
		{
			return false;
		}

		memcpy(&m_Buffer[m_nLength],
			stringImp.GetBuffer(),
			stringImp.GetLength());

		m_nLength += stringImp.GetLength();

		return true;
	}

	/// �����ַ��������β��
	bool AddChar(const char cAddChr)
	{
		if (m_nLength+1<= (size_t)max_buffer_size)
		{
			m_Buffer[m_nLength] = cAddChr;

			++m_nLength;
			return true;
		}

		return false;
	}

	/// �����ַ�������Ч���ּ��뵽�����У���׷��0�ַ�
	bool AddString(const char* pszStr)
	{
		size_t nLength = strlen(pszStr);
		return AddBuffer(pszStr, nLength);
	}

	/// �����ַ�������Ч���ֺ�0���������У�����0�ַ�
	bool AddZeroString(const char * pszStr)
	{
		return AddStringDivision(pszStr,0);
	}

	/// �����ַ�������Ч���ֵ������У��ڸ��ַ�������׷��cDiv�ַ�
	bool AddStringDivision(const char * pszStr,const char cDiv)
	{
		size_t nAddLen = strlen(pszStr);

		if (m_nLength+nAddLen+1>max_buffer_size)
		{
			return false;
		}

		memcpy(&m_Buffer[m_nLength],pszStr,nAddLen);

		m_nLength += nAddLen;
		m_Buffer[m_nLength] = cDiv;
		m_nLength += 1;

		return true;
	}; 

	/// ����stringImp�Ļ��嵽���󻺳��У�ͬʱ�ڻ����׷��cDiv�ַ�
	bool AddStringDivision(const CStringImp & stringImp,const char cDiv)
	{
		size_t nAddLen=stringImp.GetLength();

		if(m_nLength+nAddLen+1>max_buffer_size)
		{
			return false;
		}

		memcpy(&m_Buffer[m_nLength],stringImp,nAddLen);

		m_nLength += nAddLen;

		m_Buffer[m_nLength] = cDiv;
		m_nLength += 1;

		return true;
	}; 

	/// ����nLen���ֵ����ݣ��Ѻ���������ƶ�������ͷ
	void ReleaseBuffer(size_t nLen)
	{
		if (nLen >= m_nLength)
		{
			m_nLength = 0;
		}
		else
		{
			if (nLen>0)
			{
				m_nLength -= nLen;
				memcpy(m_Buffer,&m_Buffer[nLen],m_nLength);
			}
		}
	}

	/// ���Ѿ����ӵĻ����������ʽ��һ������
	/// �������ע���ڿ�ʼ��ʱ��Ҫ����������㹻�󣬷���������
	/// ע���ܳ���û�а��������0�ַ��ĳ���
	size_t AddFormat(LPCSTR lpszFormat, ...)
	{
		va_list	ap;

		va_start(ap, lpszFormat);
		m_nLength += vsprintf(m_Buffer+m_nLength, lpszFormat, ap);
		va_end(ap);

		return  m_nLength;
	}

	/// �������û�����
	void Clear()
	{
		m_nLength = 0;
		m_pBuffer = m_Buffer;
	}

	/// �ڻ�������ʼ�������һ�θ�ʽ���ַ�
	/// ע���ڸú�����ǰ������ַ��������ݻᶪʧ
	/// ע���ܳ���û�а��������0�ַ��ĳ���
	size_t Format(LPCSTR lpszFormat, ...)
	{
		va_list	ap;

		va_start(ap, lpszFormat);
		m_nLength = vsprintf(m_Buffer, lpszFormat, ap);
		va_end(ap);

		return  m_nLength;
	}

	/// ����������Ӧ���ַ�
	/// �ú�������鰲ȫ��
	char operator[](int nIndex) const
	{
		return m_Buffer[nIndex];
	}

	/// ����������Ӧ���ַ����ú�����鰲ȫ��
	/// �������Խ�� ���� 0
	const char GetAt(int nIndex) const
	{
		if (nIndex<m_nLength)
		{
			return m_Buffer[m_nLength];
		}
		else
		{
			return 0x0;
		}
	}

	/// ����nIndex��Ӧ���ַ�
	/// ����������������еĳ��ȣ�������
	void SetAt(int nIndex,const char cSet)
	{
		if (nIndex<m_nLength)
		{
			m_Buffer[m_nLength] = cSet;
		} 
	}

	bool LoadFromFile(const char * pszFileName)
	{
		FILE * pFile = fopen(pszFileName,"r");
		if (pFile == NULL)
			return false;

		int nLen = fseek(pFile,0,SEEK_END);

		if (nLen > m_nLength)
		{
			fclose(pFile);
			return false;
		}

		fseek(pFile,0,SEEK_SET);

		int nRet = fread(m_Buffer,nLen,max_buffer_size,pFile);

		fclose(pFile);

		///β���ϼ���0
		if (nRet == nLen)
		{
			m_Buffer[nLen] = 0;
			m_nLength = nLen;
			return true;
		}
		else
		{
			return false;
		}
	}

protected:
	//��4���ֽڷ�ֹ���
	char   m_Buffer[max_buffer_size+4];
};

}