Merged branches v1 and v2


	pc.printf("\n----SPI Message received!----\n");
            memcpy(&statusMessage, spiRxBuffer, sizeof(StatusMessage));

            pc.printf("remainingBattery: %d\n", statusMessage.remainingBattery);

            throttleMessage.throttle  = throttle;
            throttleMessage.rssiRx    = rssiRx;

            pc.printf("sent: %d, %d\n", throttleMessage.throttle, throttleMessage.rssiRx);
            memcpy(spiTxBuffer, &throttleMessage, sizeof(ThrottleMessage));
            spiSlave.write(spiTxBuffer, SPI_BUFFER_SIZE);