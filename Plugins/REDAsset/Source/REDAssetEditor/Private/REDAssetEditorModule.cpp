// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "REDAssetEditorModule.h"
#include "REDAnimSet.h"
#include "REDMeshArray.h"
#include "REDMeshEffect.h"
#include "REDBBSData.h"
#include "REDCollisionData.h"
#include "REDAnimArray.h"
#include "REDPawnMaterials.h"
#include "REDMeshMaterialSet.h"
#include "REDSoundCueArray.h"
#include "REDPTCColorAndMaterialAsset.h"
#include "REDParticleDataAsset.h"
#include "Modules/ModuleManager.h"
#include "Toolkits/IToolkit.h"
#include "REDAnimSetEditor.h"
#include "AssetToolsModule.h"

const FName REDAssetEditorAppIdentifier = FName(TEXT("StaticMeshEditorApp"));

#define LOCTEXT_NAMESPACE "FREDAssetEditorModule"

/**
 * StaticMesh editor module
 */

void FREDAssetEditorModule::StartupModule()
{
	MenuExtensibilityManager = MakeShareable(new FExtensibilityManager);
	ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDAnimSet()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDMeshArray()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDMeshEffect()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDBBSData()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDCollisionData()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDAnimArray()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDPawnMaterials()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDMeshMaterialSet()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDSoundCueArray()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDPTCColorAndMaterialAsset()));
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FAssetTypeActions_REDParticleDataAsset()));
}

void FREDAssetEditorModule::ShutdownModule()
{
	MenuExtensibilityManager.Reset();
	ToolBarExtensibilityManager.Reset();

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		// Unregister our custom created assets from the AssetTools
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (int32 i = 0; i < CreatedAssetTypeActions.Num(); ++i)
		{
			AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions[i].ToSharedRef());
		}
	}

	CreatedAssetTypeActions.Empty();
}

TSharedRef<IREDAnimSetEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDAnimSet* AnimSet)
{
	TSharedRef<FREDAnimSetEditor> NewCustomAssetEditor(new FREDAnimSetEditor());
	NewCustomAssetEditor->InitREDAnimSetEditorEditor(Mode, InitToolkitHost, AnimSet);
	return NewCustomAssetEditor;
}

TSharedRef<IREDMeshArrayEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshArray* MeshArray)
{
	TSharedRef<FREDMeshArrayEditor> NewCustomAssetEditor(new FREDMeshArrayEditor());
	NewCustomAssetEditor->InitREDMeshArrayEditorEditor(Mode, InitToolkitHost, MeshArray);
	return NewCustomAssetEditor;
}

TSharedRef<IREDMeshEffectEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshEffect* MeshEffect)
{
	TSharedRef<FREDMeshEffectEditor> NewCustomAssetEditor(new FREDMeshEffectEditor());
	NewCustomAssetEditor->InitREDMeshEffectEditorEditor(Mode, InitToolkitHost, MeshEffect);
	return NewCustomAssetEditor;
}

TSharedRef<IREDBBSDataEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDBBSData* BBSData)
{
	TSharedRef<FREDBBSDataEditor> NewCustomAssetEditor(new FREDBBSDataEditor());
	NewCustomAssetEditor->InitREDBBSDataEditorEditor(Mode, InitToolkitHost, BBSData);
	return NewCustomAssetEditor;
}

TSharedRef<IREDCollisionDataEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDCollisionData* CollisionData)
{
	TSharedRef<FREDCollisionDataEditor> NewCustomAssetEditor(new FREDCollisionDataEditor());
	NewCustomAssetEditor->InitREDCollisionDataEditorEditor(Mode, InitToolkitHost, CollisionData);
	return NewCustomAssetEditor;
}

TSharedRef<IREDAnimArrayEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDAnimArray* AnimArray)
{
	TSharedRef<FREDAnimArrayEditor> NewCustomAssetEditor(new FREDAnimArrayEditor());
	NewCustomAssetEditor->InitREDAnimArrayEditorEditor(Mode, InitToolkitHost, AnimArray);
	return NewCustomAssetEditor;
}

TSharedRef<IREDPawnMaterialsEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDPawnMaterials* PawnMaterials)
{
	TSharedRef<FREDPawnMaterialsEditor> NewCustomAssetEditor(new FREDPawnMaterialsEditor());
	NewCustomAssetEditor->InitREDPawnMaterialsEditorEditor(Mode, InitToolkitHost, PawnMaterials);
	return NewCustomAssetEditor;
}

TSharedRef<IREDMeshMaterialSetEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDMeshMaterialSet* MaterialSet)
{
	TSharedRef<FREDMeshMaterialSetEditor> NewCustomAssetEditor(new FREDMeshMaterialSetEditor());
	NewCustomAssetEditor->InitREDMeshMaterialSetEditorEditor(Mode, InitToolkitHost, MaterialSet);
	return NewCustomAssetEditor;
}

TSharedRef<IREDSoundCueArrayEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDSoundCueArray* SoundCueArray)
{
	TSharedRef<FREDSoundCueArrayEditor> NewCustomAssetEditor(new FREDSoundCueArrayEditor());
	NewCustomAssetEditor->InitREDSoundCueArrayEditorEditor(Mode, InitToolkitHost, SoundCueArray);
	return NewCustomAssetEditor;
}

TSharedRef<IREDPTCColorAndMaterialAssetEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDPTCColorAndMaterialAsset* PTCColorAndMaterial)
{
	TSharedRef<FREDPTCColorAndMaterialAssetEditor> NewCustomAssetEditor(new FREDPTCColorAndMaterialAssetEditor());
	NewCustomAssetEditor->InitREDPTCColorAndMaterialAssetEditorEditor(Mode, InitToolkitHost, PTCColorAndMaterial);
	return NewCustomAssetEditor;
}

TSharedRef<IREDParticleDataAssetEditor> FREDAssetEditorModule::CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UREDParticleDataAsset* ParticleData)
{
	TSharedRef<FREDParticleDataAssetEditor> NewCustomAssetEditor(new FREDParticleDataAssetEditor());
	NewCustomAssetEditor->InitREDParticleDataAssetEditorEditor(Mode, InitToolkitHost, ParticleData);
	return NewCustomAssetEditor;
}

void FREDAssetEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_GAME_MODULE(FREDAssetEditorModule, REDAssetEditor);
