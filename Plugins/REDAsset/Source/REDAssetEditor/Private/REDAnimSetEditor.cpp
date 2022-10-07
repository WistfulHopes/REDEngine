#include "REDAnimSetEditor.h"
#include "Modules/ModuleManager.h"
#include "EditorStyleSet.h"
#include "Widgets/Docking/SDockTab.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Editor.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "REDAssetEditorModule.h"

#define LOCTEXT_NAMESPACE "REDAnimSetEditor"

const FName FREDAnimSetEditor::ToolkitFName(TEXT("REDAnimSetEditor"));
const FName FREDAnimSetEditor::PropertiesTabId(TEXT("REDAnimSetEditor_Properties"));

void FREDAnimSetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDAnimSetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDAnimSetEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDAnimSetEditor::InitREDAnimSetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDAnimSet* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDAnimSetEditor_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->SetHideTabWell(true)
			->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
		)
		->Split
		(
			FTabManager::NewSplitter()
			->Split
			(
				FTabManager::NewStack()
				->AddTab(PropertiesTabId, ETabState::OpenedTab)
			)
		)
	);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDAnimSetEditor::~FREDAnimSetEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDAnimSetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDAnimSetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Set Editor");
}

FText FREDAnimSetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Set Editor");
}

FString FREDAnimSetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDAnimSetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDAnimSet* FREDAnimSetEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDAnimSetEditor::SetCustomAsset(UREDAnimSet* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDAnimSetEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "REDMeshArrayEditor"

const FName FREDMeshArrayEditor::ToolkitFName(TEXT("REDMeshArrayEditor"));
const FName FREDMeshArrayEditor::PropertiesTabId(TEXT("REDMeshArrayEditor_Properties"));

void FREDMeshArrayEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDMeshArrayEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDMeshArrayEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDMeshArrayEditor::InitREDMeshArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshArray* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDMeshArrayEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDMeshArrayEditor::~FREDMeshArrayEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDMeshArrayEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDMeshArrayEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Mesh Array Editor");
}

FText FREDMeshArrayEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Mesh Array Editor");
}

FString FREDMeshArrayEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDMeshArrayEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDMeshArray* FREDMeshArrayEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDMeshArrayEditor::SetCustomAsset(UREDMeshArray* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDMeshArrayEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "REDMeshEffectEditor"

const FName FREDMeshEffectEditor::ToolkitFName(TEXT("REDMeshEffectEditor"));
const FName FREDMeshEffectEditor::PropertiesTabId(TEXT("REDMeshEffectEditor_Properties"));

void FREDMeshEffectEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDMeshEffectEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDMeshEffectEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDMeshEffectEditor::InitREDMeshEffectEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshEffect* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDMeshEffectEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDMeshEffectEditor::~FREDMeshEffectEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDMeshEffectEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDMeshEffectEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Mesh Array Editor");
}

FText FREDMeshEffectEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Mesh Array Editor");
}

FString FREDMeshEffectEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDMeshEffectEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDMeshEffect* FREDMeshEffectEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDMeshEffectEditor::SetCustomAsset(UREDMeshEffect* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDMeshEffectEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "REDBBSDataEditor"

const FName FREDBBSDataEditor::ToolkitFName(TEXT("REDBBSDataEditor"));
const FName FREDBBSDataEditor::PropertiesTabId(TEXT("REDBBSDataEditor_Properties"));

void FREDBBSDataEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDBBSDataEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDBBSDataEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDBBSDataEditor::InitREDBBSDataEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDBBSData* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDBBSDataEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDBBSDataEditor::~FREDBBSDataEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDBBSDataEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDBBSDataEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Mesh Array Editor");
}

FText FREDBBSDataEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Mesh Array Editor");
}

FString FREDBBSDataEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDBBSDataEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDBBSData* FREDBBSDataEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDBBSDataEditor::SetCustomAsset(UREDBBSData* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDBBSDataEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "REDCollisionDataEditor"

const FName FREDCollisionDataEditor::ToolkitFName(TEXT("REDCollisionDataEditor"));
const FName FREDCollisionDataEditor::PropertiesTabId(TEXT("REDCollisionDataEditor_Properties"));

void FREDCollisionDataEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDCollisionDataEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDCollisionDataEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDCollisionDataEditor::InitREDCollisionDataEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDCollisionData* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDCollisionDataEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDCollisionDataEditor::~FREDCollisionDataEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDCollisionDataEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDCollisionDataEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Mesh Array Editor");
}

FText FREDCollisionDataEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Mesh Array Editor");
}

FString FREDCollisionDataEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDCollisionDataEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDCollisionData* FREDCollisionDataEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDCollisionDataEditor::SetCustomAsset(UREDCollisionData* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDCollisionDataEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "REDAnimArrayEditor"

const FName FREDAnimArrayEditor::ToolkitFName(TEXT("REDAnimArrayEditor"));
const FName FREDAnimArrayEditor::PropertiesTabId(TEXT("REDAnimArrayEditor_Properties"));

void FREDAnimArrayEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDAnimArrayEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDAnimArrayEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDAnimArrayEditor::InitREDAnimArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDAnimArray* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDAnimArrayEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDAnimArrayEditor::~FREDAnimArrayEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDAnimArrayEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDAnimArrayEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDAnimArrayEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDAnimArrayEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDAnimArrayEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDAnimArray* FREDAnimArrayEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDAnimArrayEditor::SetCustomAsset(UREDAnimArray* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDAnimArrayEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "REDPawnMaterialsEditor"

const FName FREDPawnMaterialsEditor::ToolkitFName(TEXT("REDPawnMaterialsEditor"));
const FName FREDPawnMaterialsEditor::PropertiesTabId(TEXT("REDPawnMaterialsEditor_Properties"));

void FREDPawnMaterialsEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDPawnMaterialsEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDPawnMaterialsEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDPawnMaterialsEditor::InitREDPawnMaterialsEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDPawnMaterials* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDPawnMaterialsEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDPawnMaterialsEditor::~FREDPawnMaterialsEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDPawnMaterialsEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDPawnMaterialsEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDPawnMaterialsEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDPawnMaterialsEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDPawnMaterialsEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDPawnMaterials* FREDPawnMaterialsEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDPawnMaterialsEditor::SetCustomAsset(UREDPawnMaterials* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDPawnMaterialsEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "REDMeshMaterialSetEditor"

const FName FREDMeshMaterialSetEditor::ToolkitFName(TEXT("REDMeshMaterialSetEditor"));
const FName FREDMeshMaterialSetEditor::PropertiesTabId(TEXT("REDMeshMaterialSetEditor_Properties"));

void FREDMeshMaterialSetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDMeshMaterialSetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDMeshMaterialSetEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDMeshMaterialSetEditor::InitREDMeshMaterialSetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDMeshMaterialSet* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDMeshMaterialSetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDMeshMaterialSetEditor::~FREDMeshMaterialSetEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDMeshMaterialSetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDMeshMaterialSetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDMeshMaterialSetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDMeshMaterialSetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDMeshMaterialSetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDMeshMaterialSet* FREDMeshMaterialSetEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDMeshMaterialSetEditor::SetCustomAsset(UREDMeshMaterialSet* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDMeshMaterialSetEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE

#define LOCTEXT_NAMESPACE "REDSoundCueArrayEditor"

const FName FREDSoundCueArrayEditor::ToolkitFName(TEXT("REDSoundCueArrayEditor"));
const FName FREDSoundCueArrayEditor::PropertiesTabId(TEXT("REDSoundCueArrayEditor_Properties"));

void FREDSoundCueArrayEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDSoundCueArrayEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDSoundCueArrayEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDSoundCueArrayEditor::InitREDSoundCueArrayEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDSoundCueArray* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDSoundCueArrayEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDSoundCueArrayEditor::~FREDSoundCueArrayEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDSoundCueArrayEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDSoundCueArrayEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDSoundCueArrayEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDSoundCueArrayEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDSoundCueArrayEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDSoundCueArray* FREDSoundCueArrayEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDSoundCueArrayEditor::SetCustomAsset(UREDSoundCueArray* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDSoundCueArrayEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "REDPTCColorAndMaterialAssetEditor"

const FName FREDPTCColorAndMaterialAssetEditor::ToolkitFName(TEXT("REDPTCColorAndMaterialAssetEditor"));
const FName FREDPTCColorAndMaterialAssetEditor::PropertiesTabId(TEXT("REDPTCColorAndMaterialAssetEditor_Properties"));

void FREDPTCColorAndMaterialAssetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDPTCColorAndMaterialAssetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDPTCColorAndMaterialAssetEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDPTCColorAndMaterialAssetEditor::InitREDPTCColorAndMaterialAssetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDPTCColorAndMaterialAsset* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDPTCColorAndMaterialAssetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDPTCColorAndMaterialAssetEditor::~FREDPTCColorAndMaterialAssetEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDPTCColorAndMaterialAssetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDPTCColorAndMaterialAssetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDPTCColorAndMaterialAssetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDPTCColorAndMaterialAssetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDPTCColorAndMaterialAssetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDPTCColorAndMaterialAsset* FREDPTCColorAndMaterialAssetEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDPTCColorAndMaterialAssetEditor::SetCustomAsset(UREDPTCColorAndMaterialAsset* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDPTCColorAndMaterialAssetEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE
#define LOCTEXT_NAMESPACE "REDParticleDataAssetEditor"

const FName FREDParticleDataAssetEditor::ToolkitFName(TEXT("REDParticleDataAssetEditor"));
const FName FREDParticleDataAssetEditor::PropertiesTabId(TEXT("REDParticleDataAssetEditor_Properties"));

void FREDParticleDataAssetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_REDAnimSsetEditor", "RED Anim Set Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FREDParticleDataAssetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FREDParticleDataAssetEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
}

void FREDParticleDataAssetEditor::InitREDParticleDataAssetEditorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UREDParticleDataAsset* InCustomAsset)
{
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	SetCustomAsset(InCustomAsset);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_REDParticleDataAssetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewStack()
					->AddTab(PropertiesTabId, ETabState::OpenedTab)
				)
			)
		);

	const bool bCreateDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor(
		Mode,
		InitToolkitHost,
		REDAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreateDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)InCustomAsset);

	// Set the asset we are editing in the details view
	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FREDParticleDataAssetEditor::~FREDParticleDataAssetEditor()
{
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FREDParticleDataAssetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FREDParticleDataAssetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "RED Anim Array Editor");
}

FText FREDParticleDataAssetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "RED Anim Array Editor");
}

FString FREDParticleDataAssetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FREDParticleDataAssetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UREDParticleDataAsset* FREDParticleDataAssetEditor::GetCustomAsset()
{
	return CustomAsset;
}

void FREDParticleDataAssetEditor::SetCustomAsset(UREDParticleDataAsset* InCustomAsset)
{
	CustomAsset = InCustomAsset;
}

TSharedRef<SDockTab> FREDParticleDataAssetEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE