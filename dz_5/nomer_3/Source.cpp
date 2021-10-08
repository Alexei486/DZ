#include <iostream>

class A
{
public:
	A(const int x,const int y):kekw(x),lol(y)
	{};
	class Key
	{
		Key() {};
		friend int get(A klass);
		friend int got(A klass);
	};
	int chat1(Key)
	{
		return kekw;
	}
	int chat2(Key)
	{
		return lol;
	}
private:
	int kekw;
	int lol;
};
int get(A klass)
{
	A::Key key;
	return klass.chat1(key);
}
int got(A klass)
{
	A::Key key2;
	return klass.chat2(key2);

}
int main()
{
    A klass(10,100);
    std::cout << get(klass);
	std::cout << "\n";
	std::cout << got(klass);
	return 0;
}