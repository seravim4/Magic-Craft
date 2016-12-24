#include "SettingsState.h"
#include "ToStringX.h"
#include "Version.h"

SettingsState::SettingsState(StateStack & stack, Context context) : State(stack, context), mGUIContainer(), mShowText(true), iskeyPressed(false)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));


	addButtonLabel(Player::Key1, 200, "", context);
	addButtonLabel(Player::Key2, 250, "", context);
	addButtonLabel(Player::Key3, 300, "", context);
	addButtonLabel(Player::Key4, 350, "", context);
	addButtonLabel(Player::Key5, 400, "", context);
	addButtonLabel(Player::Key6, 450, "", context);
	addButtonLabel(Player::Key7, 500, "", context);
	addButtonLabel(Player::Key8, 550, "", context);
	addButtonLabel(Player::Key9, 600, "", context);
	addButtonLabel(Player::Key0, 650, "", context);

	updateLabels();

	auto soundButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	soundButton->setPosition(204, 750);
	soundButton->setText("Sound");
	soundButton->setCallback
	(
		[this]()
		{
		
		}
	);

	auto credits = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	credits->setPosition(204, 800);
	credits->setText("Credits");
	credits->setCallback
	(
		[this]()
		{
			requestStackPop();
			requestStackPush(States::Credits);
		}
	);

	auto TestButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	TestButton->setPosition(204, 850);
	TestButton->setText("God Mod");
	TestButton->setCallback
	(
		[this]()
		{
			
		}
	);

	auto backButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	backButton->setPosition(204, 950);
	backButton->setText("Back");
	backButton->setCallback
	(
		[this]()
		{
			requestStackPop();
			requestStackPush(States::Menu);
		}
	);

	mGUIContainer.pack(soundButton);
	mGUIContainer.pack(credits);

	if (version != 1.f)
		mGUIContainer.pack(TestButton);
	
	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time dt)
{
	mTextEffectTime += dt;

	if (iskeyPressed == true)
		if (mTextEffectTime >= sf::seconds(3.0f) )
		{
			mShowText = false;
			requestStackPop();
			iskeyPressed = false;
		}

	return true;
}

bool SettingsState::handleEvent(const sf::Event & event)
{
	sf::RenderWindow& window = *getContext().window;
	bool IsKeyBindings = false;

	for (std::size_t action = 0; action < Player::ActionCount; ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			IsKeyBindings = true;
			if (event.type == sf::Event::KeyReleased)
			{
				getContext().players->assignKey(static_cast<Player::Action>(action), event.key.code);
				mBindingButtons[action]->deactivate();
			}
			break;
		}
	}

	if (IsKeyBindings)
		updateLabels();
	else
		mGUIContainer.handleEvent(event, window);

	return false;
}

void SettingsState::updateLabels()
{
	Player& player = *getContext().players;

	for (std::size_t i = 0; i < Player::ActionCount; ++i)
	{
		sf::Keyboard::Key key = player.getAssignedKey(static_cast<Player::Action>(i));
		mBindingButtons[i]->mText.setString(toKeyString(key));
	}
}

void SettingsState::addButtonLabel(Player::Action action, float y, const std::string& text, Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	mBindingButtons[action]->setPosition(204.f, y);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);

	mGUIContainer.pack(mBindingButtons[action]);
}
