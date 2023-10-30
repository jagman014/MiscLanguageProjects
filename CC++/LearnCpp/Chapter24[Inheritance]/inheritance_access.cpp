class Base {
public:
    int m_public {}; // accessed by anybody

protected:
    int m_protected {}; // accessed by base, friends, and derived

private:
    int m_private {}; // only accessed by base and friends
};


class Derived: public Base { 
    // public inheritance: 
    // public members stay public
    // proctected stay protected
    // private stay private
public:
    Derived() {
        m_public = 1; // allowed
        m_protected = 2; // allowed
        m_private = 3; // not allowed, not accessible by derived classes
    }
};


class Pri: private Base { // no specifier defaults to private
    // private inheritance:
    // public members become private
    // protected become private
    // private stay private
public:
    Pri() {
        m_public = 1; // ok, now private in Pri
        m_protected = 2; // ok, now private in Pri
        m_private = 3; // not ok, can't inherit private
    }
};


int main() {
    Base base;
    base.m_public = 1; // allowed
    base.m_protected = 2; // not allowed, not accessible outside class chain
    base.m_private = 3; // not allowed, not accessible outside class

    Derived pub;
    pub.m_public = 1; // allowed
    pub.m_protected = 2; // not allowed
    pub.m_private = 3; // not allowed

    Pri pri;
    pri.m_public = 1; // not allowed
    pri.m_protected = 2; // not allowed
    pri.m_private = 3; // not allowed

    return 0;
}
