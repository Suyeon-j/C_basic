struct student
{
	int id;
	char name[10];
	int grade;
};

int main() {
	int grade;

	struct student s = { 1,"castor",50 };
	struct student a[10] = { s,{2,"naever,20"} };
	struct student* p;
	Upgrade6(a);
	Upgrade7(a[1]);

	p = &s;
	(*p).grade = 100;
	p->grade = 20;
	grade = GetGrade(s);
	Upgrade(s);
	Upgrade2(&s);
	Upgrade3(&(s.grade));
	s = Upgrade4(s);
	s.grade = Upgrade5(s.grade);
}

int GetGrade(struct student a)
{
	return a.grade;
}

void Upgrade(struct student b) {
	b.grade += 10;
}

void Upgrade2(struct student* b) {
	b->grade += 10;//(*b).grade += 10;
}

void Upgrade3(int* c) {
	*c += 10;
}

struct student Upgrade4(struct student a) {
	a.grade += 10;
	return a;
}

int Upgrade5(int a)
{
	a += 10;
	return a;
}

void Upgrade6(struct student p[]) {
	p[0].grade = 100;
}

void Upgrade7(struct student a) {
	a.grade += 10;
}
