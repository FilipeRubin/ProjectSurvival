#pragma once

class IGameLogic
{
public:
	virtual ~IGameLogic() = default;
	virtual void Initialize() = 0;
	virtual void Process() = 0;
};