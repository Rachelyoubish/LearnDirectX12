#pragma once

#include <Windows.h> // For HRESULT.

// From DXSampleHelper.h 
// Source: https://github.com/Microsoft/DirectX-Graphics-Samples
inline void ThrowIfFailed( HRESULT hr )
{
    // If function returns a fail code - an exception is thrown. 
    if ( FAILED( hr ) )
    {
        throw std::exception();
    }
}