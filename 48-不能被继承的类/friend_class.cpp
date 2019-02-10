class CNoHeritance {
    friend class SealedClass;
private:
    CNoHeritance() {}
    ~CNoHeritance() {}
};



class SealedClass : virtual public CNoHeritance {
public:
    SealedClass() {}
    ~SealedClass() {}
};