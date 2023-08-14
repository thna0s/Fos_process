#include"motion.h"

EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;
EFI_GRAPHICS_OUTPUT_BLT_PIXEL Grey = {166, 166, 166, 0};
VIDEO_CONFIG videoconfig;

EFI_STATUS DrawLogo(
    IN EFI_HANDLE ImageHandle
)
{
    EFI_STATUS Status = EFI_SUCCESS;
    

    GetGopHandle(ImageHandle,&Gop);
    // int hor=videoconfig.HorizontalResolution=Gop->Mode->Info->HorizontalResolution;
    // int ver=videoconfig.VerticalResolution=Gop->Mode->Info->VerticalResolution;

    // Status = Gop->Blt(Gop, &Grey, EfiBltVideoFill, 0, 0, 0, 0, ver, hor, 0);

    SetVideoMode(Gop);

    // DrawStep(Step);

    return Status;

}


EFI_STATUS DrawStep(
    IN UINTN Step
)
{
    EFI_STATUS Status = EFI_SUCCESS;

    UINTN BlockWidth = Gop->Mode->Info->HorizontalResolution >> 6;
    UINTN BlockHeight = Gop->Mode->Info->VerticalResolution >> 6;
    UINTN StartX = (Gop->Mode->Info->HorizontalResolution - (BlockWidth + GAP) * 10 - GAP) / 2;
    UINTN StartY = (Gop->Mode->Info->VerticalResolution * 3) >> 2;

    UINTN X = StartX + (BlockWidth + GAP) * Step;

    Status = Gop->Blt(Gop, &Grey, EfiBltVideoFill, 0, 0, X, StartY, BlockWidth, BlockHeight, 0);
    
    #ifdef DEBUG
    if(EFI_ERROR(Status))
    {
        Print(L"ERROR:Failed to Blt Block.\n");
        return Status;
    }
    Print(L"SUCCESS:DrawStep:%d.\n", Step);
    #endif

    return Status;
}

EFI_STATUS SetVideoMode(
    IN EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop
)
{
    EFI_STATUS Status = EFI_SUCCESS;

    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *ModeInfo;
    UINTN ModeInfoSize = sizeof(EFI_GRAPHICS_OUTPUT_MODE_INFORMATION);
    UINTN H = 0;
    UINTN V = 0;
    UINTN ModeIndex = 0;

    for(UINTN i = 0; i < Gop->Mode->MaxMode; i++)
    {
        Status = Gop->QueryMode(Gop, i, &ModeInfoSize, &ModeInfo);
        H = ModeInfo->HorizontalResolution;
        V = ModeInfo->VerticalResolution;
        if(((H == 1024) && (V == 768)) || ((H == 1440) && (V == 900)))
        {    
            ModeIndex = i;            
        }
    }

    Status = Gop->SetMode(Gop, ModeIndex);  

    #ifdef DEBUG
    if(EFI_ERROR(Status))
    {
        Print(L"ERROR:Failed to SetMode.\n");
        return Status;
    }
    Print(L"SUCCESS:SetMode to Index:%d.\n", ModeIndex);
    
    #endif
    
    return Status;
}