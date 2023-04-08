#include <iostream>
#include <string>

class Image
{
	virtual void draw() = 0;
};

class Bitmap : public Image
{
public:
	Bitmap(std::string const& fileName)
	{
		std::cout << "Loading bitmap from: " << fileName << '\n';
	}

	void draw() override
	{
		std::cout << "Bitmap draw()\n";
	}
};

// does not load the Bitmap until the draw() method is called
class LazyBitmap : public Image
{
public:
	LazyBitmap(std::string const& fileName)
		: _fileName{fileName}
	{}

	void draw() override
	{
		if (!bmp)
		{
			bmp = new Bitmap{_fileName};
		}
		bmp->draw();
	}

private:
	std::string _fileName;
	Bitmap* bmp{nullptr};
};

int main()
{
	LazyBitmap bmp{"pokemon.png"};
	bmp.draw();
	return 0;
}
