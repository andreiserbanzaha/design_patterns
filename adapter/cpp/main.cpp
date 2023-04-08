#include <iostream>

class Plugin
{
public:
	virtual void decode() = 0;

	virtual ~Plugin() = default;
};

class WMAPlugin : public Plugin
{
public:
	void decode() 
	{
		std::cout << "[WMA Plugin] Decode()\n";
	}
};

class AACDecoder
{
public:
	void decodeStream()
	{
		std::cout << "[AAC Decoder] decodeStream()\n";
	}
};

class AACAdapter : public Plugin
{
public:
	void decode()
	{
		std::cout << "[AAC Adapter] decode()\n";
		_decoder.decodeStream();
	}

private:
	AACDecoder _decoder;
};

void playAAC(Plugin* p)
{
	p->decode();
}

int main()
{
	AACAdapter adapter;
	playAAC(&adapter);

	return 0;
}
