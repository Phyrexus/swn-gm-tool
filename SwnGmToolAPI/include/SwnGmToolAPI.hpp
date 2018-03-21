#ifndef SWN_GM_TOOL_API_HPP
#define SWN_GM_TOOL_API_HPP

#include <memory>
#include <string>

#include <cereal/cereal.hpp>

#include "ConfigModel.hpp"
#include "FactionControl.hpp"
#include "SectorGen.hpp"

namespace SwnGmTool
{
    class SwnGmToolAPI
    {
        public:
            SwnGmToolAPI(ConfigModel);
            SwnGmToolAPI(SwnGmToolAPI &&) noexcept;
            SwnGmToolAPI& operator=(SwnGmToolAPI &&) noexcept;
            ~SwnGmToolAPI();

            ConfigModel GetConfig();

            int GetFactionCount();
            Faction_List GetFactionList();
            FactionModel GetFactionDetails(int);
            void AddFaction(FactionModel);
            void RemoveFaction(int);
            void RemoveFaction(FactionModel);
            void ClearMap();

            int GetAssetCount(int);
            Asset_List GetAssetList(int);
            void AddAsset(int, AssetModel);
            void RemoveAsset(int, int);
            void ClearAssets(int);

            template <class Archive>
            void serialize(Archive& archive)
            {
                archive(cereal::make_nvp("Faction Control", *this->SGTFactionControl) );
            }

        private:
            ConfigModel SGTConfig;

            std::unique_ptr<FactionControl> SGTFactionControl;
            std::unique_ptr<SectorGen> SGTSectorGen;
    };
}

#endif
