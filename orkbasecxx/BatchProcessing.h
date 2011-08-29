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

#ifndef __BATCHPROCESSING_H__
#define __BATCHPROCESSING_H__

#include "ThreadSafeQueue.h"
#include "TapeProcessor.h"
#include "AudioTape.h"
#include "ace/Thread_Mutex.h"
#include <map>

class  BatchProcessing;
typedef boost::shared_ptr<BatchProcessing> BatchProcessingRef;

/**
 * This tape processor handles the audio transcoding
 */
class DLL_IMPORT_EXPORT_ORKBASE BatchProcessing : public TapeProcessor
{
public:
	static void Initialize();

	CStdString __CDECL__ GetName();
	TapeProcessorRef __CDECL__ Instanciate();
	void __CDECL__ AddAudioTape(AudioTapeRef& audioTapeRef);


	static void ThreadHandler(void *args);
	static bool SkipChunk(AudioTapeRef& audioTapeRef, AudioChunkRef& chunkRef, int& channelToSkip);

	void SetQueueSize(int size);

private:
	BatchProcessing();
	static TapeProcessorRef m_singleton;

	ThreadSafeQueue<AudioTapeRef> m_audioTapeQueue;

	size_t m_threadCount;
	ACE_Thread_Mutex m_mutex;
	int m_currentDay;
};

#endif

