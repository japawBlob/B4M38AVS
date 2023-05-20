#include <stdio.h>

#include "logger.h"



static uint16_t number_of_records = 0;
static uint16_t next_address = start_address+sizeof(uint16_t);
static struct data_entry * entries;

static inline void delay(vu32 nCount) {
    for (; nCount != 0; nCount--);
}

void init_logger(){
    entries = (struct data_entry*)malloc(300*sizeof(struct data_entry));
    uint16_t size = sizeof(number_of_records);
    sEE_ReadBuffer(&number_of_records, start_address, &size);
    delay(0xf);
    size = number_of_records*sizeof(struct data_entry);
    sEE_ReadBuffer(entries, start_address+sizeof(uint16_t), &size);
    sEE_WaitEepromStandbyState();
    delay(0xff);
    size = number_of_records*sizeof(struct data_entry);
    sEE_ReadBuffer(entries, start_address+sizeof(uint16_t), &size);
    delay(0xff);
    next_address = start_address+sizeof(uint16_t)+sizeof(struct data_entry)*number_of_records;  
}



void append_mem_entry(struct data_entry de){
    entries[number_of_records++] = de;
    sEE_WaitEepromStandbyState();
    sEE_WriteBuffer(&number_of_records, start_address, sizeof(uint16_t));
    sEE_WaitEepromStandbyState();
    sEE_WriteBuffer(&de, next_address, sizeof(struct data_entry));
    next_address += sizeof(struct data_entry);
}

void write_mem_entry(struct data_entry de, uint16_t address){
    sEE_WaitEepromStandbyState();
    sEE_WriteBuffer(&de, address, sizeof(struct data_entry));
    delay(0xf);
//    uint8_t buf [10];
//    uint16_t size = sizeof(de);
//    sEE_ReadBuffer(buf, address, &size);
//    int i =0;
//    for (i = 0; i<10;i++){
//        size+=14;
//    }
//    // next_address += sizeof(struct data_entry);
//    i+=size;
}

struct data_entry* get_entries(){
    return entries;
};

uint16_t get_number_of_records(){
    return number_of_records;
}

void set_number_of_records(uint16_t new_number){
    number_of_records = new_number;
    sEE_WaitEepromStandbyState();
    sEE_WriteBuffer(&number_of_records, start_address, sizeof(uint16_t));
    delay(0xf);
}

void store_record(struct data_entry de){
    store_record_at_address(de, next_address+4*sizeof(uint8_t));
    next_address += 4*sizeof(uint8_t); 
}

void store_record_at_address(struct data_entry de, uint16_t address){
    uint8_t buf [sizeof(struct data_entry)];
    int i = 0;
    buf[i++] = de.time_stamp;
    buf[i++] = de.temperature;
    buf[i++] = de.humidity;
    buf[i++] = de.vibrations;
    sEE_WriteBuffer(buf, address, sizeof(struct data_entry));
}

