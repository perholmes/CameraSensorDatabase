# Camera Sensor Database

This is a Claude Cowork job that maintains a list of cinema camera sensor sizes.

This is created for [Hollywood Camera Work](https://www.hollywoodcamerawork.com) Shot Designer (both 2D and 3D) for setting focal lengths in millimeters for 3D cameras, and for the integrated director's viewfinder.

This is provided under an MIT license. If there is any important camera or manufacturer missing from the list, please let us know.

## Running The Job

Point Claude Cowork to the repository directory, and ask it to `Execute the job in JOB.md`. The job shouldn't require any file access permissions beyond the directory, and should not need to execute any scripts at all.

## Explanation

Focal length is dependent on the sensor size. A framing made with 30mm lens on Super 35 film requires a 7.8 mm lens to achieve the same framing on a 1/2" sensor video camera.

For Shot Designer, we base our FOV calculations only on the horizontal angle, and we therefore only care about the horizontal sensor size. The vertical sensor size is provided in the CSV because it's available, but it has never been tested by us.

The following Unreal Engine-centric C++ is how we convert between field of view and lens millimeters.

```c++
float FovToFocalLength(const float FovDegrees, const float SensorWidth)
{
    // Converts the internal representation of a shot lens as a field of view in angle degrees to
    // the user-facing representation as a focal length in millimeters relative to the sensor width.
    return (SensorWidth * 0.5f) / FMath::Tan(FMath::DegreesToRadians(FovDegrees * 0.5f));
}

float FocalLengthToFov(const float FocalLength, const float SensorWidth)
{
    // Converts the user-facing representation of a shot lens as a focal length in millimeters
    // relative to the sensor width to the internal representation as a field of view in angle degrees.
    return FMath::RadiansToDegrees(2.0f * FMath::Atan(SensorWidth * 0.5f / FocalLength));
}
```

