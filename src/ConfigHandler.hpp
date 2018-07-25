#ifndef CONFIG_HANDLER
#define CONFIG_HANDLER

#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <libconfig.h++>
#include <string>
#include "Util.hpp"
using namespace libconfig;

class ConfigHandler
{
private:
    Config cfg_;
    bool created_;

    void getPathsValues_()
    {
        const Setting& pathsConf = this->cfg_.getRoot()["viewer"]["paths"];

        try
        {
            pathsConf.lookupValue("files", this->paths.files);
            pathsConf.lookupValue("output", this->paths.output);
        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Paths Settings Not Found!" << std::endl;
        }
    }

    void getScaleValues_()
    {
        const Setting& pathsConf = this->cfg_.getRoot()["viewer"]["scale"];

        try
        {
            pathsConf.lookupValue("x", this->scale.x);
            pathsConf.lookupValue("y", this->scale.y);
            pathsConf.lookupValue("z", this->scale.z);

        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Scale Settings Not Found!" << std::endl;
        }
    }

    void getResValues_()
    {
        const Setting& pathsConf = this->cfg_.getRoot()["viewer"]["pngResolution"];

        try
        {
            pathsConf.lookupValue("x", this->pngResolution.x);
            pathsConf.lookupValue("y", this->pngResolution.y);

        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Resolution Settings Not Found!" << std::endl;
        }
    }

    void getWindowValues_()
    {
        const Setting& windowConf = this->cfg_.getRoot()["viewer"]["window"];

        try
        {
            windowConf.lookupValue("title", this->window.title);
            windowConf.lookupValue("width", this->window.width);
            windowConf.lookupValue("height", this->window.height);
            windowConf.lookupValue("fullscreen", this->window.fullscreen);
        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Window Settings Not Found!" << std::endl;
        }
    }

    void getDisplayValues_()
    {
        const Setting& displayConf = this->cfg_.getRoot()["viewer"]["display"];

        try
        {
            displayConf.lookupValue("showLines", this->display.showLines);
            displayConf.lookupValue("showInfo", this->display.showInfo);
            displayConf.lookupValue("Oxigen", this->display.oxygenDisplay);
            displayConf.lookupValue("EGF", this->display.egfDisplay);

            std::string viewMode;

            displayConf.lookupValue("viewMode", viewMode);

            if(viewMode == "NUT")
                this->display.viewMode = NUT;
            else if(viewMode == "EGF")
                this->display.viewMode = EGF;
            else
                this->display.viewMode = STD;

            const Setting &linesConfig = displayConf["lines"];

            linesConfig.lookupValue("automaticPos", this->display.lines.automaticPos);
            linesConfig.lookupValue("cellGap", this->display.lines.cellGap);


            if(this->display.lines.automaticPos){
                this->display.lines.maximumLimit = Vector3();
                this->display.lines.minimumLimit = Vector3();
            } else {
                linesConfig["maximumPos"].lookupValue("x", this->display.lines.maximumLimit.x);
                linesConfig["maximumPos"].lookupValue("y", this->display.lines.maximumLimit.y);
                linesConfig["maximumPos"].lookupValue("z", this->display.lines.maximumLimit.z);

                linesConfig["minimumPos"].lookupValue("x", this->display.lines.minimumLimit.x);
                linesConfig["minimumPos"].lookupValue("y", this->display.lines.minimumLimit.y);
                linesConfig["minimumPos"].lookupValue("z", this->display.lines.minimumLimit.z);
            }


            const Setting &necConfig = displayConf["cells"]["NEC"];
            necConfig.lookupValue("visibility", this->display.cells.NEC.visibility);
            necConfig["color"]["primary"].lookupValue("r", this->display.cells.NEC.color.primary.r);
            necConfig["color"]["primary"].lookupValue("g", this->display.cells.NEC.color.primary.g);
            necConfig["color"]["primary"].lookupValue("b", this->display.cells.NEC.color.primary.b);
            necConfig["color"]["primary"].lookupValue("a", this->display.cells.NEC.color.primary.a);

            necConfig["color"]["secondary"].lookupValue("r", this->display.cells.NEC.color.secondary.r);
            necConfig["color"]["secondary"].lookupValue("g", this->display.cells.NEC.color.secondary.g);
            necConfig["color"]["secondary"].lookupValue("b", this->display.cells.NEC.color.secondary.b);
            necConfig["color"]["secondary"].lookupValue("a", this->display.cells.NEC.color.secondary.a);

            const Setting &quiConfig = displayConf["cells"]["QUI"];
            quiConfig.lookupValue("visibility", this->display.cells.QUI.visibility);
            quiConfig["color"]["primary"].lookupValue("r", this->display.cells.QUI.color.primary.r);
            quiConfig["color"]["primary"].lookupValue("g", this->display.cells.QUI.color.primary.g);
            quiConfig["color"]["primary"].lookupValue("b", this->display.cells.QUI.color.primary.b);
            quiConfig["color"]["primary"].lookupValue("a", this->display.cells.QUI.color.primary.a);

            quiConfig["color"]["secondary"].lookupValue("r", this->display.cells.QUI.color.secondary.r);
            quiConfig["color"]["secondary"].lookupValue("g", this->display.cells.QUI.color.secondary.g);
            quiConfig["color"]["secondary"].lookupValue("b", this->display.cells.QUI.color.secondary.b);
            quiConfig["color"]["secondary"].lookupValue("a", this->display.cells.QUI.color.secondary.a);

            const Setting &proConfig = displayConf["cells"]["PRO"];
            proConfig.lookupValue("visibility", this->display.cells.PRO.visibility);
            proConfig["color"]["primary"].lookupValue("r", this->display.cells.PRO.color.primary.r);
            proConfig["color"]["primary"].lookupValue("g", this->display.cells.PRO.color.primary.g);
            proConfig["color"]["primary"].lookupValue("b", this->display.cells.PRO.color.primary.b);
            proConfig["color"]["primary"].lookupValue("a", this->display.cells.PRO.color.primary.a);

            proConfig["color"]["secondary"].lookupValue("r", this->display.cells.PRO.color.secondary.r);
            proConfig["color"]["secondary"].lookupValue("g", this->display.cells.PRO.color.secondary.g);
            proConfig["color"]["secondary"].lookupValue("b", this->display.cells.PRO.color.secondary.b);
            proConfig["color"]["secondary"].lookupValue("a", this->display.cells.PRO.color.secondary.a);

            const Setting &hipConfig = displayConf["cells"]["HIP"];
            hipConfig.lookupValue("visibility", this->display.cells.HIP.visibility);
            hipConfig["color"]["primary"].lookupValue("r", this->display.cells.HIP.color.primary.r);
            hipConfig["color"]["primary"].lookupValue("g", this->display.cells.HIP.color.primary.g);
            hipConfig["color"]["primary"].lookupValue("b", this->display.cells.HIP.color.primary.b);
            hipConfig["color"]["primary"].lookupValue("a", this->display.cells.HIP.color.primary.a);

            hipConfig["color"]["secondary"].lookupValue("r", this->display.cells.HIP.color.secondary.r);
            hipConfig["color"]["secondary"].lookupValue("g", this->display.cells.HIP.color.secondary.g);
            hipConfig["color"]["secondary"].lookupValue("b", this->display.cells.HIP.color.secondary.b);
            hipConfig["color"]["secondary"].lookupValue("a", this->display.cells.HIP.color.secondary.a);

            const Setting &apoConfig = displayConf["cells"]["APO"];
            apoConfig.lookupValue("visibility", this->display.cells.APO.visibility);
            apoConfig["color"]["primary"].lookupValue("r", this->display.cells.APO.color.primary.r);
            apoConfig["color"]["primary"].lookupValue("g", this->display.cells.APO.color.primary.g);
            apoConfig["color"]["primary"].lookupValue("b", this->display.cells.APO.color.primary.b);
            apoConfig["color"]["primary"].lookupValue("a", this->display.cells.APO.color.primary.a);

            apoConfig["color"]["secondary"].lookupValue("r", this->display.cells.APO.color.secondary.r);
            apoConfig["color"]["secondary"].lookupValue("g", this->display.cells.APO.color.secondary.g);
            apoConfig["color"]["secondary"].lookupValue("b", this->display.cells.APO.color.secondary.b);
            apoConfig["color"]["secondary"].lookupValue("a", this->display.cells.APO.color.secondary.a);

            const Setting &norConfig = displayConf["cells"]["NOR"];
            norConfig.lookupValue("visibility", this->display.cells.NOR.visibility);
            norConfig["color"]["primary"].lookupValue("r", this->display.cells.NOR.color.primary.r);
            norConfig["color"]["primary"].lookupValue("g", this->display.cells.NOR.color.primary.g);
            norConfig["color"]["primary"].lookupValue("b", this->display.cells.NOR.color.primary.b);
            norConfig["color"]["primary"].lookupValue("a", this->display.cells.NOR.color.primary.a);

            norConfig["color"]["secondary"].lookupValue("r", this->display.cells.NOR.color.secondary.r);
            norConfig["color"]["secondary"].lookupValue("g", this->display.cells.NOR.color.secondary.g);
            norConfig["color"]["secondary"].lookupValue("b", this->display.cells.NOR.color.secondary.b);
            norConfig["color"]["secondary"].lookupValue("a", this->display.cells.NOR.color.secondary.a);

            const Setting &g1Config = displayConf["cells"]["G1"];
            g1Config.lookupValue("visibility", this->display.cells.G1.visibility);
            g1Config["color"]["primary"].lookupValue("r", this->display.cells.G1.color.primary.r);
            g1Config["color"]["primary"].lookupValue("g", this->display.cells.G1.color.primary.g);
            g1Config["color"]["primary"].lookupValue("b", this->display.cells.G1.color.primary.b);
            g1Config["color"]["primary"].lookupValue("a", this->display.cells.G1.color.primary.a);

            g1Config["color"]["secondary"].lookupValue("r", this->display.cells.G1.color.secondary.r);
            g1Config["color"]["secondary"].lookupValue("g", this->display.cells.G1.color.secondary.g);
            g1Config["color"]["secondary"].lookupValue("b", this->display.cells.G1.color.secondary.b);
            g1Config["color"]["secondary"].lookupValue("a", this->display.cells.G1.color.secondary.a);

            const Setting &tcConfig = displayConf["cells"]["TC"];
            tcConfig.lookupValue("visibility", this->display.cells.TC.visibility);
            tcConfig["color"]["primary"].lookupValue("r", this->display.cells.TC.color.primary.r);
            tcConfig["color"]["primary"].lookupValue("g", this->display.cells.TC.color.primary.g);
            tcConfig["color"]["primary"].lookupValue("b", this->display.cells.TC.color.primary.b);
            tcConfig["color"]["primary"].lookupValue("a", this->display.cells.TC.color.primary.a);

            tcConfig["color"]["secondary"].lookupValue("r", this->display.cells.TC.color.secondary.r);
            tcConfig["color"]["secondary"].lookupValue("g", this->display.cells.TC.color.secondary.g);
            tcConfig["color"]["secondary"].lookupValue("b", this->display.cells.TC.color.secondary.b);
            tcConfig["color"]["secondary"].lookupValue("a", this->display.cells.TC.color.secondary.a);

            const Setting &sc1Config = displayConf["cells"]["SC1"];
            sc1Config.lookupValue("visibility", this->display.cells.SC1.visibility);
            sc1Config["color"]["primary"].lookupValue("r", this->display.cells.SC1.color.primary.r);
            sc1Config["color"]["primary"].lookupValue("g", this->display.cells.SC1.color.primary.g);
            sc1Config["color"]["primary"].lookupValue("b", this->display.cells.SC1.color.primary.b);
            sc1Config["color"]["primary"].lookupValue("a", this->display.cells.SC1.color.primary.a);

            sc1Config["color"]["secondary"].lookupValue("r", this->display.cells.SC1.color.secondary.r);
            sc1Config["color"]["secondary"].lookupValue("g", this->display.cells.SC1.color.secondary.g);
            sc1Config["color"]["secondary"].lookupValue("b", this->display.cells.SC1.color.secondary.b);
            sc1Config["color"]["secondary"].lookupValue("a", this->display.cells.SC1.color.secondary.a);

            const Setting &sc2Config = displayConf["cells"]["SC2"];
            sc2Config.lookupValue("visibility", this->display.cells.SC2.visibility);
            sc2Config["color"]["primary"].lookupValue("r", this->display.cells.SC2.color.primary.r);
            sc2Config["color"]["primary"].lookupValue("g", this->display.cells.SC2.color.primary.g);
            sc2Config["color"]["primary"].lookupValue("b", this->display.cells.SC2.color.primary.b);
            sc2Config["color"]["primary"].lookupValue("a", this->display.cells.SC2.color.primary.a);

            sc2Config["color"]["secondary"].lookupValue("r", this->display.cells.SC2.color.secondary.r);
            sc2Config["color"]["secondary"].lookupValue("g", this->display.cells.SC2.color.secondary.g);
            sc2Config["color"]["secondary"].lookupValue("b", this->display.cells.SC2.color.secondary.b);
            sc2Config["color"]["secondary"].lookupValue("a", this->display.cells.SC2.color.secondary.a);
        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Display Settings Not Found!" << std::endl;
        }
    }

    void getPlayerValues_()
    {
        const Setting& conf = this->cfg_.getRoot()["viewer"]["player"];
        try
        {
            conf.lookupValue("frame", this->player.frame);

            std::string playerState;

            conf.lookupValue("state", playerState);

            if(playerState == "PLAY")
                this->player.state = PLAY;
            else if(playerState == "PREVIOUS")
                this->player.state = PREVIOUS;
            else if(playerState == "NEXT")
                this->player.state = NEXT;
            else if(playerState == "REVERSE")
                this->player.state = REVERSE;
            else if(playerState == "SHOT")
                this->player.state = SHOT;
            else
                this->player.state = PAUSE;

        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Player Settings Not Found!" << std::endl;
        }
    }

    void getCameraValues_()
    {
        const Setting& conf = this->cfg_.getRoot()["viewer"]["camera"]["pos"];
        try
        {
            conf.lookupValue("x", this->camera.pos.x);
            conf.lookupValue("y", this->camera.pos.y);
            conf.lookupValue("z", this->camera.pos.z);
        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "Camera Settings Not Found!" << std::endl;
        }
    }

    void getFileFormatValues_()
    {
        const Setting& conf = this->cfg_.getRoot()["viewer"]["file"];
        try
        {
            std::string format;
            conf.lookupValue("format", format);

            if(format == "2D" || format == "2d")
                this->fileFormat = BI_D;
            else
                this->fileFormat = TRI_D;
        }
        catch(const SettingNotFoundException &nfex)
        {
            this->created_ = false;
            std::cerr << "File Format Settings Not Found!" << std::endl;
        }
    }


    void getValues_()
    {
        this->getPathsValues_();
        this->getWindowValues_();
        this->getDisplayValues_();
        this->getPlayerValues_();
        this->getCameraValues_();
        this->getFileFormatValues_();
        this->getScaleValues_();
        this->getResValues_();
    }


public:
    ConfigHandler (std::string configFile = "config.cfg")
    {
        this->created_ = false;
        try
        {
            this->cfg_.readFile(configFile.c_str());
            this->created_ = true;
        }
        catch(const FileIOException &fioex)
        {
            std::cerr << "I/O error while reading file." << std::endl;
        }
        catch(const ParseException &pex)
        {
            std::cerr   << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                        << " - " << pex.getError() << std::endl;
        }

        this->getValues_();
    }

    Vector3 centercamera;
    bool highRes;
    int timeCounter=0;

    bool created(){
        return created_;
    }

    struct
    {
        int frame;
        PlayerStates state;
    } player;

    struct
    {
        std::string title;
        int width,
            height;
        bool fullscreen;
    } window;

    struct
    {
        std::string files,
                    output;
    } paths;

    struct
    {
        float oxygenDisplay, egfDisplay;
        bool    showLines,
                showInfo,
                lateralLine;

        ViewMode viewMode;

        CellDisplayTypes cells;

        struct
        {
            bool automaticPos;
            int cellGap;
            Vector3 maximumLimit;
            Vector3 minimumLimit;
        }lines;
    } display;

    struct
    {
        Vector3 pos;
    } camera;
    Vector3 scale;
    Vector3 pngResolution;
    FileFormat fileFormat;
};

#endif /* end of include guard: CONFIG_HANDLER */
