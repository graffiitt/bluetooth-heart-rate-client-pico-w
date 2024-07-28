#include "bluetooth/ble_client.h"

extern cvector(struct BLE_Item) bleItems;

int main()
{
    timer_hw->dbgpause = 0x2 | 0x4;
    stdio_init_all();

    ble_init();

    ble_scan_start();
    sleep_ms(10000);
    ble_scan_stop();

    for (int i = 0; i < cvector_size(bleItems); i++)
    {
        printf("\n%d id  %s name %s \n", i, cvector_at(bleItems, i)->name, bd_addr_to_str(cvector_at(bleItems, i)->address));
    }
    while (1)
    {
        /* code */
    }

    return 0;
}
