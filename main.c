/* ========================================
 *
 * Copyright Marquette University, 2021
 * Author: Carl Barcenas
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    ADC_StartConvert();
    sigBuffer_Start();
    LCD_Start();
    
    char str[10];
    int moist;
    
    for(;;)
    {
        moist = readSoil();
        
        LCD_Position(0,0);
        sprintf(str, "SM=%i", moist);
        LCD_PrintString(str);
        
        CyDelay(500);
        LCD_Position(0,0);
        LCD_PrintString("        ");
    }
}

int readSoil(void)
{
    int soilMoisture = 0; //represents the number retrieved from the sensor signal.
    int level = 0; //the "moisture level"
    
    soilMoisture = ADC_GetResult16(0u); //reads sensor
    
    
    
    return soilMoisture;
}

/* [] END OF FILE */
