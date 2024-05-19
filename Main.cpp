#include "VideoEncoder.h"

int main() {
    const char* filename = "T:\\Bastian\\Bilder\\Photon Tracer\\Videos\\test.mp4";//"c:\\temp\\1.avi";
    int width = 400;
    int height = 400;
    int fps = 25;
    int bit_rate = 200000; // 200 kbps

    VideoEncoder encoder;

    encoder.setUpEncoder(filename, width, height, fps, bit_rate);
    

    //for (int i = 0; i < 100; i++) {
    //    encoder.addFrame();
    //}
    //encoder.encodeTestVideo();
    
    encoder.encodeFromFolder("T:\\Bastian\\Bilder\\Photon Tracer\\Videos\\", "frame_", 11);

    encoder.closeEncoder();
}
