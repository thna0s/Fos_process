#include "tools.h"

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

    
    Status = gBS->OpenProtocol(
        HandleBuffer[0],
        &gEfiGraphicsOutputProtocolGuid,
        (VOID **)Gop,
        ImageHandle,
        NULL,
        EFI_OPEN_PROTOCOL_GET_PROTOCOL
    );
    
    #ifdef DEBUG
    if(EFI_ERROR(Status))
    {
        Print(L"ERROR:Failed to open first handle that supported GraphicsOutputProtocol.\n");
        return Status;
    }

    Print(L"SUCCESS:GraphicsOutputProtocol is opened with first handle.\n");
    
    #endif

    return Status;
}