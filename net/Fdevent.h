#ifndef _FDEVENT_
#define _FDEVENT_
#include <functional>
#include "../util/Nocopyable.h"
namespace ionet
{
    //事件类,
    class Fdevent:public nocopyable
    {
    public:
        //利用c++11加入的function定义回调函数
        typedef std::function<void(int)> fd_callback;
        explicit Fdevent(int fd);
        void setReadable(bool flag);
        void setWriteable(bool flag);

        void setReadCb(fd_callback cb);
        void setWriteCb(fd_callback cb);

        //事件回调函数,传入文件描述符
        void handler(int);
    private:
        int sockfd;
        bool readable;
        bool writeable;
        fd_callback read_callback;
        fd_callback write_callback;
    };
}


#endif
