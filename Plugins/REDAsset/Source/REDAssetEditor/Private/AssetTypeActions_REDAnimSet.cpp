#include "AssetTypeActions_REDAnimSet.h"
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
#include "REDAssetEditorModule.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDAnimSet"

FText FAssetTypeActions_REDAnimSet::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDAnimSet", "AssetTypeActions_REDAnimSet", "REDAnimSet");
}

FColor FAssetTypeActions_REDAnimSet::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDAnimSet::GetSupportedClass() const
{
	return UREDAnimSet::StaticClass();
}

void FAssetTypeActions_REDAnimSet::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDAnimSet>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDAnimSet::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDMeshArray"

FText FAssetTypeActions_REDMeshArray::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDMeshArray", "AssetTypeActions_REDMeshArray", "REDMeshArray");
}

FColor FAssetTypeActions_REDMeshArray::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDMeshArray::GetSupportedClass() const
{
	return UREDMeshArray::StaticClass();
}

void FAssetTypeActions_REDMeshArray::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDMeshArray>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDMeshArray::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "AssetTypeActions_REDMeshEffect"

FText FAssetTypeActions_REDMeshEffect::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDMeshEffect", "AssetTypeActions_REDMeshEffect", "REDMeshEffect");
}

FColor FAssetTypeActions_REDMeshEffect::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDMeshEffect::GetSupportedClass() const
{
	return UREDMeshEffect::StaticClass();
}

void FAssetTypeActions_REDMeshEffect::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDMeshEffect>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDMeshEffect::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDBBSData"

FText FAssetTypeActions_REDBBSData::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDBBSData", "AssetTypeActions_REDBBSData", "REDBBSData");
}

FColor FAssetTypeActions_REDBBSData::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDBBSData::GetSupportedClass() const
{
	return UREDBBSData::StaticClass();
}

void FAssetTypeActions_REDBBSData::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDBBSData>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDBBSData::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDCollisionData"

FText FAssetTypeActions_REDCollisionData::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDCollisionData", "AssetTypeActions_REDCollisionData", "REDCollisionData");
}

FColor FAssetTypeActions_REDCollisionData::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDCollisionData::GetSupportedClass() const
{
	return UREDCollisionData::StaticClass();
}

void FAssetTypeActions_REDCollisionData::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDCollisionData>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDCollisionData::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDAnimArray"

FText FAssetTypeActions_REDAnimArray::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDAnimArray", "AssetTypeActions_REDAnimArray", "REDAnimArray");
}

FColor FAssetTypeActions_REDAnimArray::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDAnimArray::GetSupportedClass() const
{
	return UREDAnimArray::StaticClass();
}

void FAssetTypeActions_REDAnimArray::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDAnimArray>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDAnimArray::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "AssetTypeActions_REDPawnMaterials"

FText FAssetTypeActions_REDPawnMaterials::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDPawnMaterials", "AssetTypeActions_REDPawnMaterials", "REDPawnMaterials");
}

FColor FAssetTypeActions_REDPawnMaterials::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDPawnMaterials::GetSupportedClass() const
{
	return UREDPawnMaterials::StaticClass();
}

void FAssetTypeActions_REDPawnMaterials::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDPawnMaterials>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDPawnMaterials::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDMeshMaterialSet"

FText FAssetTypeActions_REDMeshMaterialSet::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDMeshMaterialSet", "AssetTypeActions_REDMeshMaterialSet", "REDMeshMaterialSet");
}

FColor FAssetTypeActions_REDMeshMaterialSet::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDMeshMaterialSet::GetSupportedClass() const
{
	return UREDMeshMaterialSet::StaticClass();
}

void FAssetTypeActions_REDMeshMaterialSet::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDMeshMaterialSet>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDMeshMaterialSet::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE
#define LOCTEXT_NAMESPACE "AssetTypeActions_REDSoundCueArray"

FText FAssetTypeActions_REDSoundCueArray::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDSoundCueArray", "AssetTypeActions_REDSoundCueArray", "REDSoundCueArray");
}

FColor FAssetTypeActions_REDSoundCueArray::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDSoundCueArray::GetSupportedClass() const
{
	return UREDSoundCueArray::StaticClass();
}

void FAssetTypeActions_REDSoundCueArray::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDSoundCueArray>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDSoundCueArray::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDPTCColorAndMaterialAsset"

FText FAssetTypeActions_REDPTCColorAndMaterialAsset::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDPTCColorAndMaterialAsset", "AssetTypeActions_REDPTCColorAndMaterialAsset", "REDPTCColorAndMaterialAsset");
}

FColor FAssetTypeActions_REDPTCColorAndMaterialAsset::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDPTCColorAndMaterialAsset::GetSupportedClass() const
{
	return UREDPTCColorAndMaterialAsset::StaticClass();
}

void FAssetTypeActions_REDPTCColorAndMaterialAsset::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDPTCColorAndMaterialAsset>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDPTCColorAndMaterialAsset::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "AssetTypeActions_REDParticleDataAsset"

FText FAssetTypeActions_REDParticleDataAsset::GetName() const
{
	return NSLOCTEXT("AssetTypeActions_REDParticleDataAsset", "AssetTypeActions_REDParticleDataAsset", "REDParticleDataAsset");
}

FColor FAssetTypeActions_REDParticleDataAsset::GetTypeColor() const
{
	return FColor::Magenta;
}

UClass* FAssetTypeActions_REDParticleDataAsset::GetSupportedClass() const
{
	return UREDParticleDataAsset::StaticClass();
}

void FAssetTypeActions_REDParticleDataAsset::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto MyCustomAsset = Cast<UREDParticleDataAsset>(*ObjIt);
		if (MyCustomAsset != NULL)
		{
			FREDAssetEditorModule* CustomAssetEditorModule = &FModuleManager::LoadModuleChecked<FREDAssetEditorModule>("REDAssetEditor");
			CustomAssetEditorModule->CreateCustomAssetEditor(Mode, EditWithinLevelEditor, MyCustomAsset);
		}
	}
}

uint32 FAssetTypeActions_REDParticleDataAsset::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

#undef LOCTEXT_NAMESPACE