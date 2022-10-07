// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "REDAnimSetFactory.generated.h"

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDAnimSetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDMeshArrayFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDMeshEffectFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDBBSDataFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDCollisionDataFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDAnimArrayFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDPawnMaterialsFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDMeshMaterialSetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

/**
 *
 */
UCLASS(hidecategories = Object)
class UREDSoundCueArrayFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

UCLASS(hidecategories = Object)
class UREDPTCColorAndMaterialAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

UCLASS(hidecategories = Object)
class UREDParticleDataAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:

	//~ UFactory Interface

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};

