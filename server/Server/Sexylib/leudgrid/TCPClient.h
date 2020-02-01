#pragma once

namespace LEUD
{

class TCPClient
{
protected:
	unsigned long					m_Address;
	unsigned short					m_Port;
	SOCKET							m_socket;
	HWND							m_wnd;
protected:
	TCPClient();
	virtual ~TCPClient();
	virtual void OnSend();
public:
	void SetAddress(const char* lpszAddr);
	void SetPort( unsigned short port );

	bool Start();
	void Stop();

	void Send(const char* msg,size_t size);

	static LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
public:
	virtual void OnRecv()=0;
	virtual void OnConnect()=0;
	virtual void OnClose()=0;
	virtual void OnError(int err)=0;
public:
	static void RegWindowClass();
	static void UnregWindowClass();
};

}
	//˵��

	//start�ɹ�����б�Ҫ����stop�����ұ���Ҫ�������ر����ӡ�
	//�������ط��������ȥ����stop��
	//	1.Onerror
	//	2.Onclose
	//���ǵ����������Ƿ����˳���Ϣ������Ϣѭ������Ϊ����Ϣѭ������������stop��
	//	��ε���stop��û�й�ϵ��
	//�����Э�������������һ����Ϣ������Ȼ��ͻ��˿�ʼ�ر����ӡ�

	//ʧ�ܵ�start�ڲ������OnError��Ȼ���Զ�����stop���������Onerror���������StopҲû��ϵ����Ϊ��Щ��������stop�ǿ��Բ����ظ����ö����������ġ�
	//һ�γɹ���start�󣬻���
	//	1��1��OnConnect
	//	2��1��OnError��û���ӵ�����һ�����󣬱��������û����10061�����ӹ���Ҳ���������
	//��֮����ܻ��ж��OnError��һ�������������������û���ӵģ��������Ӷϵ����ٷ�����Ϣ������onerror��֪ͨ����

	//OnCloseֻ�ڶԷ��ر����Ӻ�֪ͨ���Լ������ر�socket�ǲ��������֪ͨ�ģ����һ�㲻���õ���
	//����������ȿ��ǵ��ǿͻ����ȷ���ر����ӣ������Լ���������Stop���ر����ӣ�ֻ���ڼ�������²���Ҫ���������ر�����

	//TCPClient �໹�ܲ����죬��Ҫ�����޸�
	//
	//���ͻ��������˾ͻ���ߣ���Ϊ���첽�ģ�������������⣬Ҫ�ر���send��onsend�ĺ�����Ŀǰ�����ˣ���������д��
