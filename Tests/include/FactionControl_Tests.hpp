#ifndef FACTION_CONTROL_TESTS_HPP
#define FACTION_CONTROL_TESTS_HPP

#include <iostream>
#include <memory>

#include "Asset.hpp"
#include "Faction.hpp"
#include "FactionControl.hpp"

#include "TestHelpers.hpp"

using namespace SwnGmTool;

namespace Tests
{
    template<typename T>
    void printList(std::vector<T> list)
    {
        for(auto i : list)
        {
            std::cout << i.Name << std::endl;
        }
    }

    void test_control()
    {
        printTestLine("Faction Control Tests");

        Faction test { "Test" };

        printTestLine("Create test control");
        std::unique_ptr<FactionControl> testControl(new FactionControl() );
        std::cout << "Control size: " << sizeof(*testControl) << "\n\n";

        {
            printTestLine("Add test faction to control");
            testControl->AddFaction(test);
            printTestLine("Show faction list");
            printList<Faction>(testControl->GetFactionList() );
            std::cout << std::endl;
        }

        {
            printTestLine("Remove faction from control");
            testControl->RemoveFaction("Test");
            printTestLine("Show faction list");
            std::cout << "Faction list:\n";
            printList<Faction>(testControl->GetFactionList() );
            std::cout << std::endl;
        }

        {
            printTestLine("Add a large amount of factions to the map");
            int test_count = 1000;
            for(int i = 0; i < test_count; i++)
            {
                std::string name = "Test" + std::to_string(i);
                std::unique_ptr<Faction> tmp = std::unique_ptr<Faction>(new Faction { name });
                testControl->AddFaction(*tmp);
            }
            std::cout << "List size: " << testControl->GetMapSize() << "\n\n";
        }

        {
            printTestLine("Clear map");
            testControl->ClearMap();
            std::cout << "List size: " << testControl->GetMapSize() << "\n\n";
        }

        {
            printTestLine("Add test faction to control");
            testControl->AddFaction(test);
            printTestLine("Show faction list");
            printList<Faction>(testControl->GetFactionList() );
            std::cout << std::endl;
        }

        {
            printTestLine("Add a large amount of assets to one faction");
            int test_count = 1000000;
            for(int i = 0; i < test_count; i++)
            {
                std::string name = "Test" + std::to_string(i);
                std::unique_ptr<Asset> tmp = std::unique_ptr<Asset>(new Asset { name });
                testControl->AddAsset("Test", *tmp);
            }
            std::cout << "List size: " << testControl->GetMapSize() << "\n\n";
            //auto map = testControl->GetMap();
            //std::cout << "Asset list size: " << map[test].size() << "\n\n";
        }

        printTestDivider('=', "\n\n");
    }
    
    template <typename T>
    void test_struct(std::string name)
    {
        printTestLine(name + " struct tests");
        
        printTestLine("Create test struct");
        T testStruct { "Test" };
        std::cout << name + " struct size: " << sizeof(testStruct) << "\n\n";
    
        printTestDivider('=', "\n\n");
    }
}

#endif
