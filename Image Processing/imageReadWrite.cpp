class chunk {
    public:
        int length;
        int type;
        char* data;
        int crc;
        chunk(int len, int typ, char* dataArg, int crcArg) {
            length=len;
            type=typ;
            crc=crcArg;
            data=dataArg;
        }
};

class pngRaw {
    public:
        int signature;
        chunk* body;
        pngRaw(int sig, chunk* bodyArg) {
            signature=sig;
            body=bodyArg;
        }
};