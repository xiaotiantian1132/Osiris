#pragma once

#include "Utils.h"
#include "Vector.h"

struct PlayerInfo {
    __int64 pad;
    union {
        __int64 steamID64;
        __int32 xuidLow;
        __int32 xuidHigh;
    };
    char name[128];
    int userId;
    char steamIdString[20];
    char pad1[16];
    unsigned long steamId;
    char friendsName[128];
    bool fakeplayer;
    bool ishltv;
    unsigned int customfiles[4];
    unsigned char filesdownloaded;
};

class NetworkChannel;

class Engine {
public:
    constexpr auto getPlayerInfo(int entityIndex, const PlayerInfo& playerInfo) noexcept
    {
        return callVirtualMethod<bool, int, const PlayerInfo&>(this, 8, entityIndex, playerInfo);
    }

    constexpr auto getLocalPlayer() noexcept
    {
        return callVirtualMethod<int>(this, 12);
    }

    constexpr auto getViewAngles(Vector& angles) noexcept
    {
        callVirtualMethod<void, Vector&>(this, 18, angles);
    }

    constexpr auto setViewAngles(const Vector& angles) noexcept
    {
        callVirtualMethod<void, const Vector&>(this, 19, angles);
    }

	constexpr auto getMaxClients() noexcept
	{
		return callVirtualMethod<int>(this, 20);
	}

	constexpr auto isInGame() noexcept
	{
		return callVirtualMethod<bool>(this, 26);
	}

    using Matrix = float[4][4];

    constexpr auto worldToScreenMatrix() noexcept
    {
        return callVirtualMethod<const Matrix&>(this, 37);
    }

    constexpr auto getNetworkChannel() noexcept
    {
        return callVirtualMethod<NetworkChannel*>(this, 78);
    }
};
