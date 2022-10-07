#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Editor/PropertyEditor/Public/PropertyEditorDelegates.h"
#include "IREDAnimSetEditor.h"

class IDetailsView;
class SDockableTab;
class UREDAnimSet;
class UREDMeshArray;
class UREDAnimArray;

/**
 *
 */
class REDASSETEDITOR_API FREDAnimSetEditor : public IREDAnimSetEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDAnimSetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDAnimSet* InCustomAsset);

	/** Destructor */
	virtual ~FREDAnimSetEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDAnimSet* GetCustomAsset();
	virtual void SetCustomAsset(UREDAnimSet* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDAnimSet* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDMeshArrayEditor : public IREDMeshArrayEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDMeshArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshArray* InCustomAsset);

	/** Destructor */
	virtual ~FREDMeshArrayEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDMeshArray* GetCustomAsset();
	virtual void SetCustomAsset(UREDMeshArray* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDMeshArray* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDMeshEffectEditor : public IREDMeshEffectEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDMeshEffectEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshEffect* InCustomAsset);

	/** Destructor */
	virtual ~FREDMeshEffectEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDMeshEffect* GetCustomAsset();
	virtual void SetCustomAsset(UREDMeshEffect* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDMeshEffect* CustomAsset;
};


/**
 *
 */
class REDASSETEDITOR_API FREDBBSDataEditor : public IREDBBSDataEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDBBSDataEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDBBSData* InCustomAsset);

	/** Destructor */
	virtual ~FREDBBSDataEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDBBSData* GetCustomAsset();
	virtual void SetCustomAsset(UREDBBSData* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDBBSData* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDCollisionDataEditor : public IREDCollisionDataEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDCollisionDataEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDCollisionData* InCustomAsset);

	/** Destructor */
	virtual ~FREDCollisionDataEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDCollisionData* GetCustomAsset();
	virtual void SetCustomAsset(UREDCollisionData* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDCollisionData* CustomAsset;
};


/**
 *
 */
class REDASSETEDITOR_API FREDAnimArrayEditor : public IREDAnimArrayEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDAnimArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDAnimArray* InCustomAsset);

	/** Destructor */
	virtual ~FREDAnimArrayEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDAnimArray* GetCustomAsset();
	virtual void SetCustomAsset(UREDAnimArray* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDAnimArray* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDPawnMaterialsEditor : public IREDPawnMaterialsEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDPawnMaterialsEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDPawnMaterials* InCustomAsset);

	/** Destructor */
	virtual ~FREDPawnMaterialsEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDPawnMaterials* GetCustomAsset();
	virtual void SetCustomAsset(UREDPawnMaterials* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDPawnMaterials* CustomAsset;
};
/**
 *
 */
class REDASSETEDITOR_API FREDMeshMaterialSetEditor : public IREDMeshMaterialSetEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDMeshMaterialSetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshMaterialSet* InCustomAsset);

	/** Destructor */
	virtual ~FREDMeshMaterialSetEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDMeshMaterialSet* GetCustomAsset();
	virtual void SetCustomAsset(UREDMeshMaterialSet* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDMeshMaterialSet* CustomAsset;
};
/**
 *
 */
class REDASSETEDITOR_API FREDSoundCueArrayEditor : public IREDSoundCueArrayEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDSoundCueArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDSoundCueArray* InCustomAsset);

	/** Destructor */
	virtual ~FREDSoundCueArrayEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDSoundCueArray* GetCustomAsset();
	virtual void SetCustomAsset(UREDSoundCueArray* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDSoundCueArray* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDPTCColorAndMaterialAssetEditor : public IREDPTCColorAndMaterialAssetEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDPTCColorAndMaterialAssetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDPTCColorAndMaterialAsset* InCustomAsset);

	/** Destructor */
	virtual ~FREDPTCColorAndMaterialAssetEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDPTCColorAndMaterialAsset* GetCustomAsset();
	virtual void SetCustomAsset(UREDPTCColorAndMaterialAsset* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDPTCColorAndMaterialAsset* CustomAsset;
};

/**
 *
 */
class REDASSETEDITOR_API FREDParticleDataAssetEditor : public IREDParticleDataAssetEditor
{
public:

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager) override;

	/**
	 * Edits the specified asset object
	 *
	 * @param	Mode					Asset editing mode for this editor (standalone or world-centric)
	 * @param	InitToolkitHost			When Mode is WorldCentric, this is the level editor instance to spawn this editor within
	 * @param	InCustomAsset			The Custom Asset to Edit
	 */
	void InitREDParticleDataAssetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDParticleDataAsset* InCustomAsset);

	/** Destructor */
	virtual ~FREDParticleDataAssetEditor();

	/** Begin IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/** End IToolkit interface */

	/** Begin ICustomAssetEditor initerface */
	virtual UREDParticleDataAsset* GetCustomAsset();
	virtual void SetCustomAsset(UREDParticleDataAsset* InCustomAsset);
	/** End ICustomAssetEditor initerface */

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;

private:
	/** Create the properties tab and its content */
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	/** Dockable tab for properties */
	TSharedPtr< SDockableTab > PropertiesTab;

	/** Details view */
	TSharedPtr<class IDetailsView> DetailsView;

	/**	The tab ids for all the tabs used */
	static const FName PropertiesTabId;

	/** The Custom Asset open within this editor */
	UREDParticleDataAsset* CustomAsset;
};