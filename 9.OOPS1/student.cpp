class Student
{
public:
    char name[100];

private:
    int rollNo;

public:
    int getRollNo()
    {
        return rollNo;
    }
    void setRollNo(int n)
    {
        this->rollNo = n;
    }
};