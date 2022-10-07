// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "IAssetTools.h"
#include "AssetTypeActions_REDAnimSet.h"

class IREDAnimSetEditor;
class UREDAnimSet;

class IREDMeshArrayEditor;
class UREDMeshArray;

class IREDMeshEffectEditor;
class UREDMeshEffect;

class IREDBBSDataEditor;
class UREDBBSData;

class IREDCollisionDataEditor;
class UREDCollisionData;

class IREDAnimArrayEditor;
class UREDAnimArray;

class IREDPawnMaterialsEditor;
class UREDPawnMaterials;

class IREDMeshMaterialSetEditor;
class UREDMeshMaterialSet;

class IREDSoundCueArrayEditor;
class UREDSoundCueArray;

class IREDPTCColorAndMaterialAssetEditor;
class UREDPTCColorAndMaterialAsset;

class IREDParticleDataAssetEditor;
class UREDParticleDataAsset;

extern const FName REDAssetEditorAppIdentifier;

class FREDAssetEditorModule : public IModuleInterface, public IHasMenuExtensibility, public IHasToolBarExtensibility
{
public:
	/** Constructor */
	FREDAssetEditorModule() { }

	/**
	* Called right after the module DLL has been loaded and the module object has been created
	*/
	virtual void StartupModule() override;

	/**
	* Called before the module is unloaded, right before the module object is destroyed.
	*/
	virtual void ShutdownModule() override;

	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDAnimSetEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDAnimSet* AnimSet);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDMeshArrayEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshArray* MeshArray);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDMeshEffectEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshEffect* MeshEffect);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDBBSDataEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDBBSData* BBSData);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDCollisionDataEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDCollisionData* CollisionData);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDAnimArrayEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDAnimArray* AnimArray);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDPawnMaterialsEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDPawnMaterials* PawnMaterials);
	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	TSharedRef<IREDMeshMaterialSetEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshMaterialSet* MaterialSet);
	
	TSharedRef<IREDSoundCueArrayEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDSoundCueArray* SoundCueArray);

	TSharedRef<IREDPTCColorAndMaterialAssetEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDPTCColorAndMaterialAsset* PTCColorAndMaterial);

	TSharedRef<IREDParticleDataAssetEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDParticleDataAsset* ParticleData);

	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);

	/** Gets the extensibility managers for outside entities to extend static mesh editor's menus and toolbars */
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override { return ToolBarExtensibilityManager; }

private:
	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};