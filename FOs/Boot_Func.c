#include"Boot_Func.h"
#include"BootLoader.h"

EFI_GRAPHICS_OUTPUT_PROTOCOL *Gop;

EFI_STATUS Draw_FOs_GRAPHICS(IN EFI_HANDLE ImageHandle)
{
    EFI_STATUS Status = EFI_SUCCESS;
    Status=GetGopHandle(ImageHandle,&Gop);
    return Status;
}

EFI_STATUS GetGopHandle(
    IN EFI_HANDLE ImageHandle,
    OUT EFI_GRAPHICS_OUTPUT_PROTOCOL **Gop
)
{
    EFI_STATUS Status = EFI_SUCCESS;
    UINTN HandleCount = 0;
    EFI_HANDLE *HandleBuffer;
    Status = gBS->LocateHandleBuffer(
        ByProtocol,
        &gEfiGraphicsOutputProtocolGuid,
        NULL,
        &HandleCount,
        &HandleBuffer
    );

    Print(L"HandleCount = %d\n",HandleCount);


    Status = gBS->OpenProtocol(
        HandleBuffer[0],
        &gEfiGraphicsOutputProtocolGuid,
        (VOID **)Gop,
        ImageHandle,
        NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL
    );
    


    return Status;
}

