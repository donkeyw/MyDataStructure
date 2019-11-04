#ifndef __NON_COPYABLE_H__
#define __NON_COPYALBE_H__

class NonCopyable
{
public:
    NonCopyable();
    ~NonCopyable();
private:
    NonCopyable(const NonCopyable&);
    const NonCopyable& operator = (const NonCopyable&);
};

#endif