METASOURCES = AUTO
lib_LTLIBRARIES = libvoip.la
libvoip_la_SOURCES = VoIpConfig.cpp VoIp.cpp Rtp.cpp Iax2Session.cpp RtpSession.cpp \
	SipTcp.cpp AudioCapturePluginCommon.cpp PacketHeaderDefs.cpp
libvoip_la_LDFLAGS = -module
AM_CPPFLAGS = -D_REENTRANT
libvoip_la_LIBADD = -lACE -lxerces-c -llog4cxx -lorkbase -lpcap
INCLUDES = -I@top_srcdir@ -I../../../orkbasecxx -I../common
AudioCapturePluginCommon.cpp:
	ln -s ../common/AudioCapturePluginCommon.cpp AudioCapturePluginCommon.cpp
