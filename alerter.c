#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    
    int threshold = 200;
    int alert = 0;
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius >= threshold)
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        alert = 500;
    }
    else
    {
        alert = 200;
    }

    return alert;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
