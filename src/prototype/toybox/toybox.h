#ifndef __TOY_BOX_H__
#define __TOY_BOX_H__

class SmallToyImpl;

class SmallToy
{
public:
    enum
    {
        MaxSize = 100 // max toy size
    };

protected:
    SmallToyImpl *pImpl;

public:
    SmallToy() = default;
    virtual ~SmallToy() = default;

    // No Copying
    SmallToy(const SmallToy &) = delete;
    SmallToy &operator=(const SmallToy &) = delete;

    const int GetToyMaxSize();
    bool checkData() const;
};

class ToyBase
{
private:
    int id;

public:
    ToyBase()
    {

    }

    virtual ~ToyBase() {};

    ToyBase(const ToyBase& toy)
    {
        this->id = toy.id;
    }

    Toy& operator=(const ToyBase& toy)
    {
        this->id = toy.id;
        return *this;
    }
}

#endif