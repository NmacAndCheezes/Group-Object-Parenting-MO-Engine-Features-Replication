#pragma once
#include "AUIScreen.h"
#include  "../GraphicsEngine.h"

class CreditsScreen : public AUIScreen
{
public:
	CreditsScreen();
	virtual void update() override;
	~CreditsScreen();

private:
	TexturePtr m_image;
};

