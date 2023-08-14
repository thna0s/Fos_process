#include "boot.h"


EFI_STATUS
EFIAPI 
UefiMain(EFI_HANDLE ImageHandle,EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_STATUS Status = EFI_SUCCESS;
    DrawLogo(ImageHandle);

    UINT8 Step = 1;
    DrawStep(Step++);

    
    while (1)
    {
        /* code */
    }
    

    return Status;
}
