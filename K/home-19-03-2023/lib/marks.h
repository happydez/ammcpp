namespace amm {

    struct Bonus {
    private:
        int _attestat;
        int _gto;
        int _other;
    
    public:
        // ctor
        Bonus(){};
        Bonus(int, int, int){};

        int GetAttestat();
        int GetGto();
        int GetOther();
        int All();
    };

    class Marks {
    private:
        int _russian;
        int _math;
        int _physics;
        int _informatics;
        int _obsh;
        bool _ok;
            
    public:
        // ctor
        Marks(){}
        Marks(int, int, int, int, int){}

        // getters
        int GetRussian();
        int GetMath();
        int GetPhysics();
        int GetInformatics();
        int GetObsh();
        bool IsValid();

        static bool IsValidMark(int);
    };
}