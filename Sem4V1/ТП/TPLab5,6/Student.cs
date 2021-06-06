namespace WindowsFormsApp1
{
    class Student
    {
        readonly string FIO;
        readonly byte SchoolNum, ClassNum, TestMark;
        public Student(string FIO, byte SchoolNum, byte ClassNum, byte TestMark)
        {
            this.FIO = FIO;
            this.SchoolNum = SchoolNum;
            this.ClassNum = ClassNum;
            this.TestMark = TestMark;
        }
        public override string ToString()
        {
            return FIO;
        }
        public string GetFIO {
            get
            {
                return FIO;
            }
        }
        public byte GetSchoolNum
        {
            get
            {
                return SchoolNum;
            }
        }
        public byte GetClassNum
        {
            get
            {
                return ClassNum;
            }
        }
        public byte GeTestMark
        {
            get
            {
                return TestMark;
            }
        }
    }
}
