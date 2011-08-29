/*
 * Oreka -- A media capture and retrieval platform
 *
 * Copyright (C) 2005, orecx LLC
 *
 * http://www.orecx.com
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License.
 * Please refer to http://www.gnu.org/copyleft/gpl.html
 *
 */

#ifndef _SIPTCP_H__
#define _SIPTCP_H__ 1

#include <log4cxx/logger.h>
#include <list>
#include "SipTcp.h"
#include <map>
#include "ace/Singleton.h"
#include "PacketHeaderDefs.h"

using namespace log4cxx;

class SafeBuffer
{
public:
        SafeBuffer();
        ~SafeBuffer();

        void Store(u_char *buf, int len);
	void Add(u_char *buf, int len);
        u_char *GetBuffer();
        int Size();

private:
        u_char *m_pBuffer;
        int m_size;
};
typedef boost::shared_ptr<SafeBuffer> SafeBufferRef;

// ============================================================

class SipTcpStream
{
public:
	SipTcpStream();
	~SipTcpStream();
	void ToString(CStdString& string);
	void AddTcpPacket(u_char *pBuffer, int packetLen);
	bool SipRequestIsComplete();
	SafeBufferRef GetCompleteSipRequest();

	struct in_addr m_senderIp;
	struct in_addr m_receiverIp;
	int m_senderPort;
	int m_receiverPort;
	unsigned long int m_expectingSeqNo;
	unsigned long int m_lastSeqNo;

	int m_entryTime;
private:
	SafeBufferRef m_sipRequest;
};
typedef boost::shared_ptr<SipTcpStream> SipTcpStreamRef;

#endif

