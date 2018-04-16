#pragma once

class UCharacter;
class Spawner
{
public:
	virtual ~Spawner(){ }
	virtual UCharacter *spawnCharacter() = 0;
};

template<class T>
class SpawnerFor :
	public Spawner
{
private:
	T *prototype;
public:
	UCharacter *spawnCharacter() { return new T; }
};