// Copyright Hollywood Camera Work

// For Shot Designer, drop all three cpp/h files into ShotDesigner/UI/Cameras

#pragma once

#include "CoreMinimal.h"

struct FCameraSensor
{
    FString Manufacturer;
    FString Camera;
    FString Format;
    FVector2D SensorSize;
};

class FCameraSensors
{
public:
    static const TArray<FCameraSensor>& All();

    static TArray<FString> GetManufacturers();
    static TArray<FString> GetCameras(const FString& Manufacturer);
    static TArray<FString> GetFormats(const FString& Manufacturer, const FString& Camera);
    static TOptional<FVector2D> GetSensorSize(const FString& Manufacturer, const FString& Camera, const FString& Format);

    static FString ConcatenateSensorDescription(const FString& Manufacturer, const FString& Camera, const FString& Format);
    static bool ParseSensorDescription(const FString& Description, FString& OutManufacturer, FString& OutCamera, FString& OutFormat);
};
