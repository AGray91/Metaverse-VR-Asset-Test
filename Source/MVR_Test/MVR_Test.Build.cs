// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MVR_Test : ModuleRules
{
	public MVR_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[]
		{
			"MVR_Test/Public/Pawns",
			"MVR_Test/Public/Actor_Components",
			"MVR_Test/Public/UI",
			"MVR_Test/Public/Game_Mode",
			"MVR_Test/Public/Game_State"
		});

		PrivateIncludePaths.AddRange(new string[]
		{
			"MVR_Test/Private/Pawns",
			"MVR_Test/Private/Actor_Components",
			"MVR_Test/Private/UI",
			"MVR_Test/Private/Game_Mode",
            "MVR_Test/Private/Game_State"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
