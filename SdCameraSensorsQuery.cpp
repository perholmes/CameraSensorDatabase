// Copyright Hollywood Camera Work
// Query helpers for FCameraSensors. Only called from the project settings dialogue and the shot
// configuration dialogue — runs as part of UI interaction, not in a hot path, so brute-force
// search through All() is fine.

#include "SdCameraSensors.h"

TArray<FString> FCameraSensors::GetManufacturers()
{
    TArray<FString> Result;
    for (const FCameraSensor& Sensor : All()) {
        Result.AddUnique(Sensor.Manufacturer);
    }
    return Result;
}

TArray<FString> FCameraSensors::GetCameras(const FString& Manufacturer)
{
    TArray<FString> Result;
    for (const FCameraSensor& Sensor : All()) {
        if (Sensor.Manufacturer == Manufacturer) {
            Result.AddUnique(Sensor.Camera);
        }
    }
    return Result;
}

TArray<FString> FCameraSensors::GetFormats(const FString& Manufacturer, const FString& Camera)
{
    TArray<FString> Result;
    for (const FCameraSensor& Sensor : All()) {
        if (Sensor.Manufacturer == Manufacturer && Sensor.Camera == Camera) {
            Result.Add(Sensor.Format);
        }
    }
    return Result;
}

TOptional<FVector2D> FCameraSensors::GetSensorSize(const FString& Manufacturer, const FString& Camera, const FString& Format)
{
    for (const FCameraSensor& Sensor : All()) {
        if (Sensor.Manufacturer == Manufacturer && Sensor.Camera == Camera && Sensor.Format == Format) {
            return Sensor.SensorSize;
        }
    }
    return TOptional<FVector2D>();
}

FString FCameraSensors::ConcatenateSensorDescription(const FString& Manufacturer, const FString& Camera, const FString& Format)
{
    return Manufacturer + TEXT(" ") + Camera + TEXT(" ") + Format;
}

TOptional<FSensorDescriptionResult> FCameraSensors::ParseSensorDescription(const FString& Description)
{
    for (const FCameraSensor& Sensor : All()) {
        if (ConcatenateSensorDescription(Sensor.Manufacturer, Sensor.Camera, Sensor.Format) == Description) {
            return FSensorDescriptionResult{ Sensor.Manufacturer, Sensor.Camera, Sensor.Format };
        }
    }
    return {};
}
