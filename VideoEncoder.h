#ifndef VIDEOENCODER_H
#define VIDEOENCODER_H

#include <string>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
}

class VideoEncoder {
	
public:
	bool setUpEncoder(std::string filename, int width, int height, int fps, int bitrate);
	bool encodeFromFolder(std::string folder, std::string prefix, int numberOfFrames);
	bool addFrame(const uint8_t* src, int src_linesize);
	bool encodeTestVideo();
	bool closeEncoder();
	
private:
	AVFrame* read_png_to_avframe(const char* filename);
	
	AVFormatContext* fmt_ctx;
	AVCodecContext* codec_ctx;
	AVStream* stream;
	AVPacket* pkt;
	AVFrame* frame;

	int frameNumber;
};



#endif //VIDEOENCODER_H
