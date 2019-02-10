class SealedClass {
public:
    friend SealedClass* GetInstance();

private:
    SealedClass() {}
    ~SealedClass(){}
};

SealedClass* GetInstance() {
    return new SealedClass();
}

class Base : public SealedClass {};