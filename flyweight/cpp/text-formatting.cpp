#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class FormattedText
{
public:
	FormattedText(std::string const& plainText)
		: _plainText{plainText}
	{
		_caps = new bool[_plainText.length()];
		std::memset(_caps, 0, _plainText.length());
	}

	~FormattedText()
	{
		delete _caps;
	}

	std::string const& getPlainText() const
	{
		return _plainText;
	}

	bool* getCaps() const
	{
		return _caps;
	}

	void capitalize(int start, int end)
	{
		for (int i = start; i < end; ++i)
		{
			_caps[i] = true;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, FormattedText const& obj)
	{
		std::string s;
		for (int i = 0; i < obj.getPlainText().length(); ++i)
		{
			char c = obj.getPlainText()[i];
			s += (obj.getCaps()[i] ? std::toupper(c) : c);
		}
		os << s;
		return os;
	}

private:
	std::string _plainText;
	bool* _caps;
};

class BetterFormattedText
{
public:
	struct TextRange
	{
		int start;
		int end;
		bool capitalize; // italic, bold etc

		bool covers(int position) const
		{
			return position >= start && position <= end;
		}
	};

	TextRange& getRange(int start, int end)
	{
		_formatting.emplace_back(TextRange{start, end});
		return *_formatting.rbegin();
	}

	BetterFormattedText(std::string const& plainText)
		: _plainText{plainText}
	{}

	std::string const& getPlainText() const
	{
		return _plainText;
	}

	friend std::ostream& operator<<(std::ostream& os, 
			BetterFormattedText const& obj)
	{
		std::string s;
		for (int i = 0; i < obj.getPlainText().length(); ++i)
		{
			auto c = obj.getPlainText()[i];
			for (auto const& range : obj._formatting)
			{
				if (range.covers(i) && range.capitalize)
				{
					c = std::toupper(c);
				}
				s += c;
			}
		}
		return os << s;
	}

private:
	std::string _plainText;
	std::vector<TextRange> _formatting;
};

int main()
{
	FormattedText ft {"This is a brave new world"};
	ft.capitalize(10, 15);

	std::cout << ft << '\n';

	// ----------------------------

	BetterFormattedText bft{"This is a brave new world"};
	bft.getRange(10, 15).capitalize = true;
	std::cout << bft << '\n';

	return 0;
}
