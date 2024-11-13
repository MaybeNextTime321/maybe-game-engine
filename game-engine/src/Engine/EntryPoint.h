#pragma once

// clang-format off

#ifdef MB_PLATFORM_WINDOWS

extern Maybe::Application *CreateApplication();

int main(int argc, char **argv)
{
    Maybe::Log::Init();
    auto *sb = CreateApplication();
    sb->Run();
    delete sb;
}

#else
#error We support only windows for now
#endif

// clang-format on