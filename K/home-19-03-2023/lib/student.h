namespace amm {
    class Student
    {
    private:
        int _id;
        std::string _name;
        std::string _surname;
        Marks _marks;
        Bonus _bonus;
        
    public:
        // ctor
        Student(int, std::string, std::string, Marks, Bonus);
        
        std::string String() {
            return this->_name + " " + this->_surname;
        }
    };
}