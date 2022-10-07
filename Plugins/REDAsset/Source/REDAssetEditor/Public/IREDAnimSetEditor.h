#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"

class UREDAnimSet;

class UREDMeshArray;

class UREDBBSData;

/**
 * Public interface to Custom Asset Editor
 */
class IREDAnimSetEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDAnimSet* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDAnimSet* InCustomAsset) = 0;
}; 

class IREDMeshArrayEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDMeshArray* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDMeshArray* InCustomAsset) = 0;
};

class IREDMeshEffectEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDMeshEffect* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDMeshEffect* InCustomAsset) = 0;
};

class IREDBBSDataEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDBBSData* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDBBSData* InCustomAsset) = 0;
};

class IREDCollisionDataEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDCollisionData* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDCollisionData* InCustomAsset) = 0;
};

class IREDAnimArrayEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDAnimArray* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDAnimArray* InCustomAsset) = 0;
};

class IREDPawnMaterialsEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDPawnMaterials* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDPawnMaterials* InCustomAsset) = 0;
};

class IREDMeshMaterialSetEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDMeshMaterialSet* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDMeshMaterialSet* InCustomAsset) = 0;
};

class IREDSoundCueArrayEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDSoundCueArray* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDSoundCueArray* InCustomAsset) = 0;
};

class IREDPTCColorAndMaterialAssetEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDPTCColorAndMaterialAsset* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDPTCColorAndMaterialAsset* InCustomAsset) = 0;
};

class IREDParticleDataAssetEditor : public FAssetEditorToolkit
{
public:
	/** Retrieves the current custom asset. */
	virtual UREDParticleDataAsset* GetCustomAsset() = 0;

	/** Set the current custom asset. */
	virtual void SetCustomAsset(UREDParticleDataAsset* InCustomAsset) = 0;
};