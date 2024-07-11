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


class png {
    public:
        int height;
        int width;
        int** red;
        int** blue;
        int** green;
        png(int heightArg, int widthArg, int** redArg, int** blueArg, int** greenArg) {
            height=heightArg;
            width=widthArg;
            red=redArg;
            blue=blueArg;
            green=greenArg;
        }
};

