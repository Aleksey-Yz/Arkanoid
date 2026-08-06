// Alexey Tishaninov. All rights reserved.


#include "Witgets/PauseWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ResumeButton)
		ResumeButton->OnReleased.AddDynamic(this, &UPauseWidget::ResumeGame);
	if (RestartButton)
		RestartButton->OnReleased.AddDynamic(this, &UPauseWidget::RestartGame);
	if (MenuButton)
		MenuButton->OnReleased.AddDynamic(this, &UPauseWidget::BackToMenu);
}

void UPauseWidget::ResumeGame()
{
	OnGameResume.Broadcast();
}

void UPauseWidget::RestartGame()
{
	const auto LevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}

void UPauseWidget::BackToMenu()
{
	UGameplayStatics::OpenLevel(this, FName("Menu"));
}

void UPauseWidget::SetWinStatus(const bool bWinStatus)
{
	if (!StatusText)
		return;

	if (ResumeButton)
	{
		ResumeButton->SetIsEnabled(false);
		ResumeButton->SetVisibility(ESlateVisibility::Hidden);
	}

	if (bWinStatus)
	{
		StatusText->SetText(FText::FromString("You win"));
		StatusText->SetColorAndOpacity(FColor::Green);
	}
	else
	{
		StatusText->SetText(FText::FromString("You lose"));
		StatusText->SetColorAndOpacity(FColor::Red);
	}
}