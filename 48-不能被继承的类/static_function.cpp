class SealedClass {
public:
    static SealedClass* GetInstance() {
        return new SealedClass();
    }

private:
    SealedClass() {}
    ~SealedClass(){}
};

class Base : public SealedClass {};