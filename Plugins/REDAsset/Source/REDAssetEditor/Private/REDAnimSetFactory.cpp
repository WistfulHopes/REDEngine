// Fill out your copyright notice in the Description page of Project Settings.


#include "REDAnimSetFactory.h"

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

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDAnimSetFactory::UREDAnimSetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDAnimSet::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDAnimSetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDAnimSet>(InParent, InClass, InName, Flags);
}


bool UREDAnimSetFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDMeshArrayFactory::UREDMeshArrayFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDMeshArray::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDMeshArrayFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDMeshArray>(InParent, InClass, InName, Flags);
}


bool UREDMeshArrayFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDMeshEffectFactory::UREDMeshEffectFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDMeshEffect::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDMeshEffectFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDMeshEffect>(InParent, InClass, InName, Flags);
}


bool UREDMeshEffectFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDBBSDataFactory::UREDBBSDataFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDBBSData::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDBBSDataFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UE_LOG(LogTemp, Warning, TEXT("In name is %s"), *InName.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Parent full name is %s"), *InParent->GetFullName());
	return NewObject<UREDBBSData>(InParent, InClass, InName, Flags);
}


bool UREDBBSDataFactory::ShouldShowInNewMenu() const
{
	return true;
}


/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDCollisionDataFactory::UREDCollisionDataFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDCollisionData::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDCollisionDataFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDCollisionData>(InParent, InClass, InName, Flags);
}


bool UREDCollisionDataFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDAnimArrayFactory::UREDAnimArrayFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDAnimArray::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDAnimArrayFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDAnimArray>(InParent, InClass, InName, Flags);
}

bool UREDAnimArrayFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDPawnMaterialsFactory::UREDPawnMaterialsFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDPawnMaterials::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDPawnMaterialsFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDPawnMaterials>(InParent, InClass, InName, Flags);
}

bool UREDPawnMaterialsFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDMeshMaterialSetFactory::UREDMeshMaterialSetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDMeshMaterialSet::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDMeshMaterialSetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDMeshMaterialSet>(InParent, InClass, InName, Flags);
}

bool UREDMeshMaterialSetFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDSoundCueArrayFactory::UREDSoundCueArrayFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDSoundCueArray::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDSoundCueArrayFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDSoundCueArray>(InParent, InClass, InName, Flags);
}

bool UREDSoundCueArrayFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDPTCColorAndMaterialAssetFactory::UREDPTCColorAndMaterialAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDPTCColorAndMaterialAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDPTCColorAndMaterialAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDPTCColorAndMaterialAsset>(InParent, InClass, InName, Flags);
}

bool UREDPTCColorAndMaterialAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}

/* UTextAssetFactoryNew structors
 *****************************************************************************/

UREDParticleDataAssetFactory::UREDParticleDataAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UREDParticleDataAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UREDParticleDataAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UREDParticleDataAsset>(InParent, InClass, InName, Flags);
}

bool UREDParticleDataAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}
